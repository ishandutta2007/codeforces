#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[300003],Cnt[703],nxt[300003],T,a;
vector<int>V[2003],v;
bool cmp(int x,int y){return x>y;}
long long calc(int x,int y){
	return v[x]+v[y];
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;v.clear();
		map<int,int>mp,tmp,MP;
		map<pair<int,int>,bool>bad,vis;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			v.push_back(a);
			tmp[a]++;
		}sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int i=0;i<v.size();i++)
			mp[v[i]]=i;
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x=mp[x];y=mp[y];
//			cout<<x<<' '<<y<<endl;
			bad[make_pair(x,y)]=1;
			bad[make_pair(y,x)]=1;
		}
		int N=0;
		for(int i=0;i<v.size();i++){
			cnt[i]=tmp[v[i]];
			if(!MP[cnt[i]]){
				Cnt[N]=cnt[i];
				MP[cnt[i]]=N++;
			}
			V[MP[cnt[i]]].push_back(i);
		}
		for(int i=0;i<N;i++){
			sort(V[i].begin(),V[i].end(),cmp);
			for(int j=1;j<V[i].size();j++)
				nxt[V[i][j-1]]=V[i][j];
			nxt[V[i].back()]=-1;
		}
		long long ans=0;
		for(int i=0;i<N;i++)
			for(int j=i;j<N;j++){
				priority_queue<pair<long long,pair<int,int> > >Q;
				Q.push(make_pair(calc(V[i][0],V[j][0]),make_pair(V[i][0],V[j][0])));
				vis[make_pair(V[i][0],V[j][0])]=1;
				vis[make_pair(V[j][0],V[i][0])]=1;
				while(Q.size()){
					pair<long long,pair<int,int> >nw=Q.top();Q.pop();
					if(!bad[nw.second]&&nw.second.first!=nw.second.second){ans=max(ans,(Cnt[i]+Cnt[j])*nw.first);break;}
					int x=nw.second.first,y=nw.second.second;
					if(nxt[x]!=-1&&!vis[make_pair(nxt[x],y)]){
						Q.push(make_pair(calc(nxt[x],y),make_pair(nxt[x],y)));
						vis[make_pair(nxt[x],y)]=1;
						vis[make_pair(y,nxt[x])]=1;
					}
					if(nxt[y]!=-1&&!vis[make_pair(x,nxt[y])]){
						Q.push(make_pair(calc(x,nxt[y]),make_pair(x,nxt[y])));
						vis[make_pair(x,nxt[y])]=1;
						vis[make_pair(nxt[y],x)]=1;
					}
				}
			}
		cout<<ans<<endl;
		for(int i=0;i<N;i++)
			V[i].clear();
	}
}