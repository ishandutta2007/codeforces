#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int p[30];
char a[100010],b[100010];

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]>b[i]){
				flag=false;break;
			}
		}
		if(!flag) cout<<-1<<'\n';
		else{
			int ans=0;
			for(int i=1;i<=26;i++) p[i]=i;
			for(int i=1;i<=n;i++){
				int x=a[i]-'a'+1,y=b[i]-'a'+1;
				if(x==y) continue;
				int rootx=find_set(x),rooty=find_set(y);
				if(rootx==rooty) continue;
				p[rooty]=rootx;
				ans++;
			}
			cout<<ans<<'\n';
		}
	} 
	return 0;
}