#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
int ans=0;
deque<pair<int,int> > a[4];
int get_front(deque<pair<int,int> >& a){
	pair<int,int> x=a.front(); a.pop_front();
	x.second--;
	if(x.second>0) a.push_front(x);
	return x.first;
}
int get_back(deque<pair<int,int> >& a){
	pair<int,int> x=a.back(); a.pop_back();
	x.second--;
	if(x.second>0) a.push_back(x);
	return x.first;
}
bool check(int t){
	int x=(t+3)&3,y=(t+1)&3,cnt,key;
	pair<int,int> k=a[t].front(); a[t].pop_front();
	while(!a[t].empty()&&a[t].front().first==k.first){
		k.second+=a[t].front().second;
		a[t].pop_front();
	}
	a[t].push_front(k);
	if(a[t].size()>1) return true;
	if(k.first==a[x].back().first&&k.first==a[y].front().first)
		return false;
	return true;
}
void remove(int t){
	int x=(t+3)&3,y=(t+1)&3,cnt,key;
//	printf("<%d %d %d>\n",x,t,y);
	bool flag=0;
	cnt=0; key=get_back(a[x]);
	while(!a[t].empty()&&key==a[t].front().first){
		cnt+=a[t].front().second;
		a[t].pop_front();
	}
	if(a[t].empty()) a[t].push_front(make_pair(key,cnt+1));
	else{
		get_front(a[t]);
		if(cnt>0) a[t].push_front(make_pair(key,cnt));
		flag=1;
		++ans;
	}
	cnt=0; key=get_front(a[y]);
	if(flag){
		a[t].push_back(make_pair(key,1));
		return;
	}
	while(!a[t].empty()&&key==a[t].back().first){
		cnt+=a[t].back().second;
		a[t].pop_back();
	}
	if(a[t].empty()){
		if(!flag){
			if(cnt>1) a[t].push_back(make_pair(key,cnt-1));
		}
		else a[t].push_back(make_pair(key,cnt+1));
	}
	else{
		get_back(a[t]);
		if(cnt>0) a[t].push_back(make_pair(key,cnt));
		++ans;
	}
}
char s[N];
int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<4;++i){
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;++j)
			if(s[j]=='R') a[i].push_back(make_pair(0,1));
			else a[i].push_back(make_pair(1,1));
		if(i==1||i==2) reverse(a[i].begin(),a[i].end());
	}
	swap(a[0],a[2]);
	swap(a[2],a[1]);
	swap(a[2],a[3]);
/*	for(int i=0;i<4;++i){
		for(int j=0;j<a[i].size();++j)
			printf("<%d %d>",a[i][j].first,a[i][j].second);
		puts("");
	}
*///	exit(0);
//	printf("{%d %d}\n",n,m);
	while(n>1||m>1){
		if(n>m){
			if(check(0)) remove(0);
			else remove(2);
			--n;
		}
		else{
			if(check(1)) remove(1);
			else remove(3);
			--m;
		}
/*		cerr<<"A"<<endl;
		for(int i=0;i<4;++i){
			for(int j=0;j<a[i].size();++j)
				printf("<%d %d>",a[i][j].first,a[i][j].second);
			puts("");
		}
		printf("|%d|\n",ans);
*/	}
//	exit(0);
	ans+=2-abs(a[0].front().first+a[1].front().first+a[2].front().first+a[3].front().first-2);
	printf("%d\n",ans);
	return 0;
}