#include<bits/stdc++.h>
using namespace std;
vector<pair<vector<int>,vector<int> > > g;
struct Checker{
	int n,cnt,p[10005];
	int read(){
		scanf("%d",&n); cnt=0;
		for(int i=1;i<=n;++i) p[i]=i;
		random_shuffle(p+1,p+n+1);
		if(p[1]>n/2)
			for(int i=1;i<=n;++i) p[i]=n-p[i]+1;
		return n;
	}
	int query(vector<int> a){
		++cnt;
		int sum=0;
		for(auto x:a) sum+=p[x];
		int ret=int(sum%a.size()==0);
		printf("?");
		for(auto x:a) printf(" %d",x);
		puts("");
		printf("[%d]\n",ret);
		return ret;
	}
	void finish(vector<int> a){
		for(auto x:a) printf("<%d>",x); puts("");
		for(int i=1;i<=n;++i) printf("|%d|",p[i]); puts("");
		for(int i=0;i<a.size();++i)
			if(a[i]!=p[i+1]){
				puts("GG");
				exit(0);
			}
		printf("You take %d/%d queries\n",cnt,18*n);
		exit(0);
	}
}checker;
int query(vector<int> a){
	if(a.size()<=1) return 1;
//	return checker.query(a);
	printf("? %d ",(int)a.size());
	for(auto x:a) printf("%d ",x); puts("");
	fflush(stdout);
	int ans; scanf("%d",&ans);
	return ans;
}
vector<int> rev(vector<int> a){
	for(int i=0;i<a.size();++i) 
		a[i]=a.size()-a[i]+1;
	return a;
}
void finish(vector<int> a){
	if(a[0]>a.size()/2)
		a=rev(a);
//	return checker.finish(a);
	printf("! ");
	for(auto x:a) printf("%d ",x); puts("");
	fflush(stdout);
	exit(0);
}

int main(){
	srand(time(0));
	int n=checker.read();
	g.resize(2);
	for(int i=1;i<=n;++i){
		g[1].first.push_back(i);
		g[1].second.push_back(i);
	}
	int t=1;
	while(1){
		vector<int> a;
		for(int i=t;i<t+t;++i){
			if(g[i].first.size()<2)
				goto __flag1;
			a.push_back(g[i].first[0]);
			a.push_back(g[i].first[1]);
		}
		int type=query(a);
		for(int i=t;i<t+t;++i){
			int pos=(i-t)*2;
			vector<int> f0,f1;
			f0.push_back(g[i].first[0]);
			if(g[i].first.size()==2) 
				f1.push_back(g[i].first[1]);
			for(int j=2;j<g[i].first.size();++j){
				vector<int> b=a; b[pos]=g[i].first[j];
				int type1=query(b);
				if(type==type1)
					f0.push_back(g[i].first[j]);
				else
					f1.push_back(g[i].first[j]);
				if(j==2){
					vector<int> c=a; c[pos+1]=g[i].first[j];
					if(query(c)==type1)
						f0.push_back(g[i].first[1]);
					else
						f1.push_back(g[i].first[1]);
				}
			}
			if(f0.size()<f1.size())
				swap(f0,f1);
			sort(f0.begin(),f0.end());
			sort(f1.begin(),f1.end());
			g.push_back(make_pair(f0,vector<int>()));
			g.push_back(make_pair(f1,vector<int>()));
		}
		t<<=1;
	}
	__flag1:;
	for(int i=t;i<t+t;++i){
		for(int j=0;j<g[i].first.size();++j)
			g[i].second.push_back(j+1);
	}
/*	for(int i=1;i<t+t;++i){
		printf("|%d|",i);
		for(auto x:g[i].first) printf("(%d)",x);
		puts("");
	}
	puts("");
*/	while(t>1){
		t=t>>1;
		for(int i=t;i<t+t;++i){
			auto f0=g[i+i],f1=g[i+i+1];
			if(g[i].first.size()%2==0){
				vector<int> pos;
				for(int j=0;j<f0.first.size();++j)
					if(f0.second[j]==1||f0.second[j]==f0.second.size()){
						vector<int> a=g[i].first;
						a.erase(lower_bound(a.begin(),a.end(),f0.first[j]));
						if(query(a)) pos.push_back(f0.first[j]);
					}
				for(int j=0;j<f1.first.size();++j)
					if(f1.second[j]==1||f1.second[j]==f1.second.size()){
						vector<int> a=g[i].first;
						a.erase(lower_bound(a.begin(),a.end(),f1.first[j]));
						if(query(a)) pos.push_back(f1.first[j]);
					}
//				for(auto x:pos) printf("|%d|",x); puts("");
//				exit(0);
				if(pos.size()!=2) assert(0);
				if(find(f0.first.begin(),f0.first.end()
					,pos[0])==f0.first.end())
					swap(f0,f1);
				for(int j=0;j<f0.first.size();++j){
					if(f0.first[j]==pos[0]){
						if(f0.second[j]!=1)
							f0.second=rev(f0.second);
						if(f0.second[j]!=1)
							assert(0);
					}
				}
				for(int j=0;j<f1.first.size();++j){
					if(f1.first[j]==pos[1]){
						if(f1.second[j]!=f1.second.size())
							f1.second=rev(f1.second);
						if(f1.second[j]!=f1.second.size())
							assert(0);
					}
				}
			}else{
				vector<int> a;
				for(int j=0;j<f0.first.size();++j)
					if(f0.second[j]!=1)
						a.push_back(f0.first[j]);
				for(int j=0;j<f1.first.size();++j)
					a.push_back(f1.first[j]);
				for(int j=0;j<f1.first.size();++j){
					if(f1.second[j]==1||f1.second[j]==f1.second.size()){
						vector<int> b=a;
						b.erase(lower_bound(b.begin(),b.end(),f1.first[j]));
						if(query(b)){
							if(f1.second[j]==f1.second.size()){
								f1.second=rev(f1.second);
								break;
							}
						}
					}
				}
			}
			int poi0=0,poi1=0;
			g[i].second.resize(g[i].first.size());
			for(int j=0;j<g[i].second.size();++j){
				if(poi0<f0.first.size()&&(poi1>=f1.first.size()
					||f0.first[poi0]<f1.first[poi1])){
					g[i].second[j]=f0.second[poi0]*2-1;
					++poi0;
				}else{
					g[i].second[j]=f1.second[poi1]*2;
					++poi1;
				}
			}
		}
	}
/*	for(int i=1;i<g.size();++i){
		printf("|%d|",i);
		for(auto x:g[i].first) printf("[%d]",x);
		for(auto x:g[i].second)	
			printf("(%d)",x);
		puts("");
	}
	puts("");
*/	finish(g[1].second);
	return 0;
}