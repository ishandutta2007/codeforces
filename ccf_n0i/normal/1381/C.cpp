#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int t,n,x,y,z;
int i,j,vis[100005],a[100005],b[100005],mex;
vector<int> pos[100005];
set<pair<int,int> > s;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&x,&y);y-=x;z=n-x-y;
		rep(i,n+1)pos[i].clear();s.clear();
		rep(i,n+1)vis[i]=0;
		rep(i,n) {b[i]=0;scanf("%d",&a[i]);vis[a[i]]=1;pos[a[i]].push_back(i);}
		mex=1;while(vis[mex])mex++;
		rep(i,n+1)if(pos[i].size()) s.insert(make_pair(pos[i].size(),i));
		while(x--){
			int t=s.rbegin()->second;s.erase(*s.rbegin());
			b[pos[t].back()]=t;pos[t].pop_back();
			if(pos[t].size()) s.insert(make_pair(pos[t].size(),t));
		}
		vector<int> v;
		v.resize(y+z);
		rep(i,n+1)pos[i].clear();
		rep(i,n) if(!b[i]) {pos[a[i]].push_back(i);}
		if(z==0){
			int lst=0;
			int mx=0;
			rep(i,n+1)if(pos[i].size()){
				if(pos[i].size()>pos[mx].size()) mx=i;
			}
			for(j=0;j<pos[mx].size();j++){
				v[lst]=pos[mx][j];
				lst=(lst+2);
				if(lst>=y) lst=1;
			}
			rep(i,n+1)if(i!=mx)for(j=0;j<pos[i].size();j++){
				v[lst]=pos[i][j];
				lst=(lst+2);
				if(lst>=y) lst=1;
			}
			for(i=0;i<v.size();i++){
//				cerr<<v[i]<<' ';
				b[v[i]]=a[v[(i+1)%y]];
			}
			bool f=1;
			for(i=0;i<v.size();i++){
				if(a[v[i]]==b[v[i]]){
					f=0;break;
				}
			}
			if(f){
				puts("YES");
				rep(i,n){
					printf("%d%c",b[i],(i==n?'\n':' '));
				}
			}
			else{
				puts("NO");
			}
			continue;
		}
		int f=1;
		rep(i,z){
			int t=s.rbegin()->second;s.erase(*s.rbegin());
			b[pos[t].back()]=mex;int lst=pos[t].back();pos[t].pop_back();
			if(pos[t].size()) s.insert(make_pair(pos[t].size(),t));
			while(y>0){
				y--;
				int t1=s.rbegin()->second;s.erase(*s.rbegin());
				if(t1==a[lst]){
					if(s.empty()){
						f=0;break;
					}
					int t2=s.rbegin()->second;s.erase(*s.rbegin());
					b[pos[t2].back()]=a[lst];lst=pos[t2].back();pos[t2].pop_back();
					if(pos[t2].size()) s.insert(make_pair(pos[t2].size(),t2));
				}
				else{
					b[pos[t1].back()]=a[lst];lst=pos[t1].back();pos[t1].pop_back();
				}
				if(pos[t1].size()) s.insert(make_pair(pos[t1].size(),t1));
			}
			if(!f) break;
		}
		if(!f||y){
			puts("NO");
			continue;
		}
		puts("YES");
		rep(i,n){
			printf("%d%c",b[i],(i==n?'\n':' '));
		}
	} 
	return 0;
}