#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n;
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		ll d,m;cin>>d>>m;
		ll a=2,b=1,ans=0;
		for(i=1;i<=30;i++){
			if(d>=(1ll<<i)){
				ans=(ans+(1ll<<i-1)*b)%m;
				b=b*a%m;
				a=a*2-1;
			}
			else{
				ans=(ans+(d-(1ll<<i-1)+1)*b)%m;
				cout<<ans<<endl;
				break;
			}
		}
	}
	return 0;
}