#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const int M=1000005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll a[N];
ll cnt[M];
void build(int x){
	for(int i=2;i*i<=x;i++){
		ll k=0;
		while(x%i==0){
			k++;
			x/=i;
		}
		cnt[i]=max(cnt[i],k);
	}
	if(x>1) cnt[x]=max(cnt[x],1ll);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		ll mx=0;
		for(i=1;i<=n;i++){
			cin>>a[i];mx=max(mx,a[i]);
			build(a[i]);
		}
		ll k=1,o=0,f,ans=1;
		for(i=1;i<M;i++){
			if(cnt[i]){
				o++;f=i;
				k*=cnt[i]+1;
				while(cnt[i]--)
					ans*=i;
				cnt[i]=0;
			}
		}
		if(k==n+2){
			if(mx==ans) cout<<-1<<endl;
			else cout<<ans<<endl;
		}
		else if(k==n+1&&o==1) cout<<ans*f<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}