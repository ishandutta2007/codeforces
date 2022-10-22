#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
const int mod=998244353;
int n,m;
int a[N],d[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) d[i]=1;
		for(i=1;i<=n;i++) cin>>a[i];
		int answ=0;
		int ans=0;
		for(i=1;i<=n;i++){
			int x=a[i];
			for(j=i-1;j;j--){
				if((a[j]+d[j]-1)/d[j]<=x) break;
				ans=(ans-1ll*(d[j]-1)*j%mod+mod)%mod;
				while((a[j]+d[j]-1)/d[j]>x){
					int t=a[j]/(a[j]/d[j]);
					if((a[j]+t-1)/t==(a[j]+d[j]-1)/d[j]) t++;
					d[j]=t;
				}
				x=a[j]/d[j];
				ans=(ans+1ll*(d[j]-1)*j)%mod;
			}
			answ=(answ+ans)%mod;
		}
		cout<<answ<<endl;
	}
	return 0;
}