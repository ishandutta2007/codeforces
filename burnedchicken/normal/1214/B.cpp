#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int b,g,n;
	cin >> b >> g >> n;
	if(n<=min(b,g)) cout << n+1 << "\n";
	else if(n<=max(b,g)) cout << min(b,g)+1 << "\n";
	else cout << b+g-n+1 << "\n";
	return 0;
}