#include<bits/stdc++.h>
using namespace std;
int n,a[1003],fr[1000003],FR[1003];
int w[1003][1003],lst[1000003];
int q[1000003],s,t,sz=0,V[1000003];
bool vis[1003],vis2[1000003];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	vector<int>v;
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			v.push_back(a[j]*i);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	map<int,int>mp;
	for(int i=0;i<v.size();i++)
		mp[v[i]]=i;
	for(int i=0;i<n;i++)
		for(int j=1;j<=n;j++)
			w[i][j-1]=mp[a[i]*j];
	long long ans=0;
	memset(fr,-1,sizeof(fr));
	for(int i=0;i<n;i++){
		s=0,t=-1;
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		q[++t]=i;
		while(s<=t){
			int nw=q[s++];
			for(int i=0;i<n;i++)
				if(!vis2[w[nw][i]]){
					vis2[w[nw][i]]=1;
					lst[w[nw][i]]=nw;
					if(fr[w[nw][i]]!=-1)
						if(!vis[fr[w[nw][i]]])
							vis[fr[w[nw][i]]]=1,
							q[++t]=fr[w[nw][i]];
				}
		}
		for(int j=0;j<v.size();j++)
			if(vis2[j]&&fr[j]==-1){
				int nw=j+n;sz=0;
				while(nw!=i){
					V[sz++]=nw;
					if(nw<n)
						nw=FR[nw]+n;
					else
						nw=lst[nw-n];
				}V[sz++]=nw;
				while(sz){
					FR[V[sz-1]]=V[sz-2]-n;
					fr[V[sz-2]-n]=V[sz-1];
					sz-=2;
				}ans+=v[j];
				break;
			}
	}cout<<ans;
}