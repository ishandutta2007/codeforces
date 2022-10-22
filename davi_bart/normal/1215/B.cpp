#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ll N;
		cin>>N;
		ll tot=0;
		ll prec1=1,prec2=0;
		bool c=1;
		for(ll i=0;i<N;i++){
			ll a;
			cin>>a;
			if(a<0)c=!c;
			if(c){
				tot+=prec1;
				prec1++;
			}else{
				tot+=prec2;
				prec2++;
			}
		}
		cout<<(N*(N+1))/2-tot<<" "<<tot;
		return 0;
}