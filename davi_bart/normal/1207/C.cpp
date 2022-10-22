#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll T;
		cin>>T;
		while(T--){
			ll N,a,b;
			cin>>N>>a>>b;
			string c;
			cin>>c;
			ll tot=a*N+b*(N+1);
			vector<ll> uno;
			vector<ll> pp;
			uno.push_back(1);
			for(ll i=1;i<c.size();i++){
				if(c[i]=='0'){
					if(c[i-1]=='0')uno.back()++;
					else uno.push_back(1);
				}else{
				  if(c[i-1]=='1')pp.back()++;
					else pp.push_back(1);
					tot+=b;
				}
			}
			tot+=b*pp.size();
			if(uno.size()==1){
				cout<<tot<<endl;
				continue;
			}
			tot+=2*a;
			for(ll i=1;i<uno.size()-1;i++){
				tot+=min(b*(uno[i]-1),2*a);
			}
			cout<<tot<<endl;
		}
		return 0;
}