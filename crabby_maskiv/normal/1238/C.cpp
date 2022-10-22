#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
    int i,j;
    int T;cin>>T;
    while(T--){
    	ll x;cin>>x>>n;
    	for(i=1;i<=n;i++) cin>>a[i];
    	int ans=0;
    	a[n+1]=0;
    	for(i=1;i<=n;i++){
    		if(a[i]>a[i+1]+1) a[i]=a[i+1]+1;
    		if(i==n) continue;
    		if(a[i+1]>a[i+2]+1){
    			ans++;
    			a[i+1]--;
			}
			else i++;
		}
		cout<<ans<<endl;
	}
    return 0;
}