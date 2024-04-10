#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	if(e>=f){
		if(a>=d) cout << d*e << "\n";
		else cout << a*e+min(min(b,c),d-a)*f << "\n";
	}
	else{
		if(min(b,c)>=d) cout << d*f << "\n";
		else cout << min(b,c)*f+min(a,d-min(b,c))*e << "\n";
	}
	return 0;
}