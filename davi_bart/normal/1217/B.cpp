#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ll T;
		cin>>T;
		while(T--){
			ll N,vita;
			cin>>N>>vita;
			ll danno=0,guad=-100000000000;
			for(ll i=0;i<N;i++){
				ll a,b;
				cin>>a>>b;
				danno=max(danno,a);
				guad=max(guad,a-b);
			}
			if(danno>=vita)cout<<1<<'\n';
			else if(guad<=0 && danno<vita)cout<<-1<<'\n';
			else{
        ll p=(vita-danno)/guad;
        if(p*guad<vita-danno)p++;
        cout<<1+p<<'\n';
			}
		}
		return 0;
}