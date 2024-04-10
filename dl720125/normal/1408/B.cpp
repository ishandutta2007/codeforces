#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,k,a[110],b[110];
bool vis[110];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		int cnt=0;
		while(true){
			cnt++;
			int tot=0,pos=-1;
			for(int i=0;i<=100;i++) vis[i]=0;
			for(int i=1;i<=n;i++){
				if(!vis[a[i]]) vis[a[i]]=1,tot++;
				if(tot==k){
					pos=i;break;
				}
			}
			if(pos==-1){
				cout<<cnt<<'\n';break;
			}
			int val=a[pos];
			for(int i=1;i<pos;i++) b[i]=0;
			for(int i=pos;i<=n;i++) b[i]=a[i]-val;
			bool flag1=true;
			for(int i=1;i<=n;i++) if(b[i]!=0){
				flag1=false;break;
			}
			if(flag1){
				cout<<cnt<<'\n';break;
			}
			bool flag2=true;
			for(int i=1;i<=n;i++) if(b[i]!=a[i]){
				flag2=false;break;
			}
			if(flag2){
				cout<<-1<<'\n';break;
			}
			for(int i=1;i<=n;i++) a[i]=b[i];
		}
	}
	return 0;
}