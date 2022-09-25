#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(long long i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,x;
	cin >> n;
	bool t=true;
	loop(n){
		cin >> x;
		if(x%2==0) cout << x/2 << endl;
		else{
			if(t){
				if(x>0) cout << x/2+1 << endl;
				else cout << x/2 << endl;
				t=false;
			}
			else{
				if(x>0) cout << x/2 << endl;
				else cout << x/2-1 << endl;
				t=true;
			}
		}
	}
	return 0;
}