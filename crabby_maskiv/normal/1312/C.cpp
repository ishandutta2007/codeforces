#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
const ll mod=998244353;
int n,m;
ll k;
ll a[N];
int vis[60];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>k;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			cin>>a[i];
			for(j=0;j<60;j++){
				vis[j]+=a[i]%k;
				a[i]/=k;
			}
		}
		for(j=0;j<60;j++){
			if(vis[j]>1){
				cout<<"NO"<<endl;
				break;
			}
		}
		if(j==60) cout<<"YES"<<endl;
	}
	return 0;
}