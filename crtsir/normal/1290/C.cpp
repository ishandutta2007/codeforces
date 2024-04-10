#include<bits/stdc++.h>
using namespace std;
int n,k,fa[300003],ans,ty[300003],cnt[300003][2],x[300003],m;
vector<int>v[300003],g[300003];
string s;
int main(){
	cin>>n>>m>>s; 
	for(int i=0;i<m;i++){int sz,a;cin>>sz;while(sz--)cin>>a,a--,v[i].push_back(a),g[a].push_back(i);fa[i]=i;ty[i]=-1;cnt[i][0]=1;}
	for(int i=0;i<n;i++)
		if(g[i].size()==0)
			cout<<ans<<endl;
		else
			if(g[i].size()==1){
				int j;for(j=g[i][0],k=0;fa[j]!=j;j=fa[j])k^=x[j];k=k^(s[i]-'0');
				if(ty[j]==-1){ty[j]=k;ans-=min(cnt[j][0],cnt[j][1]);ans+=cnt[j][k];}
				cout<<ans<<endl;
			}else{
				int j=g[i][0],k=g[i][1],a=x[j],b=x[k];
				while(fa[j]!=j)j=fa[j],a^=x[j];while(fa[k]!=k)k=fa[k],b^=x[k];
				if(j!=k){
					if(cnt[j][0]+cnt[j][1]<cnt[k][0]+cnt[k][1])swap(j,k);
					if(ty[j]==-1)ans-=min(cnt[j][0],cnt[j][1]);else ans-=cnt[j][ty[j]];
					if(ty[k]==-1)ans-=min(cnt[k][0],cnt[k][1]);else ans-=cnt[k][ty[k]];
					fa[k]=j;
					if(a^b^('1'-s[i])){x[k]=1;swap(cnt[k][0],cnt[k][1]);if(ty[k]!=-1)ty[k]=1-ty[k];}
					cnt[j][0]+=cnt[k][0];cnt[j][1]+=cnt[k][1];
					if(ty[k]!=-1)ty[j]=ty[k];
					if(ty[j]==-1)ans+=min(cnt[j][0],cnt[j][1]);else ans+=cnt[j][ty[j]];
				}
				cout<<ans<<endl;
			}
}