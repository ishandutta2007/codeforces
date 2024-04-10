#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
const int mod=1e9+7;
int n,m;
int a[N];
int p2[N];
int c[30];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	p2[0]=1;
	for(i=1;i<=n;i++) p2[i]=(p2[i-1]<<1)%mod;
	for(i=1;i<=n;i++){
		for(j=0;j<30;j++){
			if(a[i]>>j&1){
				c[j]++;
				break;
			}
		}
	}
	int s=0,ans=p2[n]-1;
	for(i=29;i;i--){
		if(!c[i]) continue;
		ans=(ans-1ll*p2[c[i]-1]*p2[s]%mod+mod)%mod;
		s+=c[i];
	}
	cout<<ans;
	return 0;
}