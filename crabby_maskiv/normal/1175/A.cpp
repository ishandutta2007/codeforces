#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;

int main(){
	ios::sync_with_stdio(0);
	int i,j;
	ll a,b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		ll ans=0;
		while(a){
			if(a%b==0){
				a/=b;
				ans++;
			}
			else{
				ans+=a%b;
				a=(a/b)*b;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}