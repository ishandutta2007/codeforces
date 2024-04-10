#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t,a,b,n;
	cin >> t;
	loopi(noob,t){
		cin >> a >> b >> n;
		if(n%3==0) cout << a << "\n";
		else if(n%3==1) cout << b << "\n";
		else cout << (a^b) << "\n";
	}
	return 0;
}