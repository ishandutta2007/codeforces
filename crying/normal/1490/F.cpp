#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MAXN=2e5+10,INF=1e9;
int T,n,a[MAXN]; 
int v[MAXN],tot,sum[MAXN],ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		tot=0;
		ans=INF;
		rep(i,1,n){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		int cnt=1;
		rep(i,2,n){
			if(a[i]!=a[i-1]){
				v[++tot]=cnt;
				cnt=1;
			}else cnt++;
		}
		v[++tot]=cnt;
		sort(v+1,v+1+tot);
		sum[0]=1;
		rep(i,1,tot){
			sum[i]=sum[i-1]+v[i];
		}
		rep(i,1,tot){
			int cost=n-v[i]*(tot-i+1); 
			ans=min(ans,cost);
		}
		cout<<ans<<endl;
	}
	return 0;
}