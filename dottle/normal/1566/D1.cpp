#include<bits/stdc++.h>
#define int long long
const int N=350;

using namespace std;

vector<int> p[N];


int t,n,m,v[N],a[N];
main(){
	ios::sync_with_stdio(false);
	cin>>t;
	a[0]=1.1e9;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=m;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=m;i++){
			int p=0;
			for(int i=1;i<=m;i++)
				if(a[i]<a[p]&&!v[i])
					p=i;
			for(int i=1,s=0;i<=m;i++){
				s+=v[i];
				if(a[i]==a[p])
					ans+=s,v[i]=1;
			}
		}
		memset(v,0,sizeof(v));
		cout<<ans<<endl;
	}
}