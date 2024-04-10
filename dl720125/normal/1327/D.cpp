#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

int p[200010],c[200010],nxt[200010];
bool vis[200010],used[200010];
vector<int> res;

inline void dfs(int x)
{
	vis[x]=1;
	res.push_back(x);
	if(vis[nxt[x]]) return;
	dfs(nxt[x]);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			vis[i]=0;nxt[i]=0;
		}
		for(int i=1;i<=n;i++){cin>>p[i];nxt[i]=p[i];}
		for(int i=1;i<=n;i++) cin>>c[i];
		int ans=INF;
		for(int i=1;i<=n;i++) if(!vis[i]){
			res.clear();
			dfs(i);
			int len=res.size();
			int num=INF;
			for(int j=1;j*j<=len;j++) if(len%j==0){
				int val=j;
				bool flag=false;
				for(int k=0;k<val;k++) used[k]=1;
				for(int k=0;k<res.size();k++){
					if(c[res[k]]!=c[res[(k+val)%len]]){
						used[k%val]=0;
					}
				}
				for(int k=0;k<val;k++) if(used[k]) flag=true;
				if(flag){
					num=val;
					break;
				}
			}
			if(num!=INF){
				ans=min(ans,num);
				continue;
			}
			for(int j=int(sqrt(len));j>=1;j--) if(len%j==0){
				int val=len/j;
				bool flag=false;
				for(int k=0;k<val;k++) used[k]=1;
				for(int k=0;k<res.size();k++){
					if(c[res[k]]!=c[res[(k+val)%len]]){
						used[k%val]=0;
					}
				}
				for(int k=0;k<val;k++) if(used[k]) flag=true;
				if(flag){
					num=val;
					break;
				}
			}
			ans=min(ans,num);
		}
		cout<<ans<<endl;
	}
	return 0;
}