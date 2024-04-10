#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll k;
ll a[N];
ll mn=inf;
priority_queue<pair<ll,int> > q;
int main(){
	ios::sync_with_stdio(0);
    int i,j;
    cin>>n>>k;
    for(i=1;i<=n;i++){
    	cin>>a[i];
    	mn=min(mn,a[i]);
	}
	ll ans=0;
	while(k>=mn){
		int cnt=0;
		ll pri=0;
		for(i=1;i<=n;i++){
			if(k>=a[i]){
				pri+=a[i];
				k-=a[i];
				cnt++;
			}
		}
		ans+=k/pri*cnt+cnt;
		k%=pri;
	}
	cout<<ans;
    return 0;
}