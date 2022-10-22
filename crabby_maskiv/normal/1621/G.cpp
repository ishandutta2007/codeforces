#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int mod=1e9+7;
int n,m;
int a[N],x[N];
int w1[N],w2[N],w3[N],mx[N],pos[N];
int stk[N],top;
#define lbt(x) (x&(-x))
int d1[N],d2[N];
vector<int> v[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,k;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) x[i]=a[i];
		sort(x+1,x+n+1);
		m=unique(x+1,x+n+1)-(x+1);
		for(i=1;i<=n;i++) a[i]=lower_bound(x+1,x+m+1,a[i])-x;
		for(i=1;i<=n;i++){
			w1[i]=1;
			for(j=a[i]-1;j;j-=lbt(j)){
				w1[i]=(w1[i]+d1[j])%mod;
				w2[i]=(w2[i]+d2[j])%mod;
			}
			w2[i]=(w2[i]+w1[i])%mod;
			for(j=a[i];j<=m;j+=lbt(j)){
				d1[j]=(d1[j]+w1[i])%mod;
				d2[j]=(d2[j]+w2[i])%mod;
			}
		}
		for(i=n;i;i--) mx[i]=max(mx[i+1],a[i]);
		int ans=0;
		for(i=1;i<=n;i++){
			if(a[i]<mx[i+1])
				ans=(ans+w2[i])%mod;
		}
		for(i=1;i<=n;i++) d1[i]=0;
		for(i=n;i;i--){
			w3[i]=(a[i]>mx[i+1]);
			for(j=a[i]+1;j<=m;j+=lbt(j)) w3[i]=(w3[i]+d1[j])%mod;
			for(j=a[i];j;j-=lbt(j)) d1[j]=(d1[j]+w3[i])%mod;
		}
		for(i=1;i<=n;i++) d1[i]=0;
		for(i=n;i;i--){
			if(a[i]>mx[i+1])
				stk[++top]=a[i];
		}
		for(i=n;i;i--){
			if(a[i]>=mx[i+1]){
				w3[i]=1;
				pos[i]=mx[i+1];
			}
			else{
				pos[i]=upper_bound(stk+1,stk+top+1,a[i])-stk-1;
				v[pos[i]].push_back(i);
				pos[i]=stk[pos[i]];
			}
		}
		for(i=1;i<=m;i++){
			for(auto x:v[i]){
				w3[x]=1;
				for(j=a[x]+1;j<=m;j+=lbt(j)) w3[x]=(w3[x]+d1[j])%mod;
				for(j=a[x];j;j-=lbt(j)) d1[j]=(d1[j]+w3[x])%mod;
			}
			for(auto x:v[i])
				for(j=a[x];j;j-=lbt(j)) d1[j]=0;
		}
		for(i=1;i<=n;i++){
			int s=0;
			for(j=pos[i]-1;j>0;j-=lbt(j)) s=(s+d1[j])%mod;
			ans=(ans+1ll*w3[i]*s)%mod;
			for(j=a[i];j<=m;j+=lbt(j)) d1[j]=(d1[j]+w2[i])%mod;
		}
		cout<<ans<<endl;
		for(i=1;i<=n;i++) d1[i]=d2[i]=w1[i]=w2[i]=w3[i]=stk[i]=mx[i]=a[i]=0;
		for(i=1;i<=n;i++) v[i].clear();
		top=0;
	}
	return 0;
}