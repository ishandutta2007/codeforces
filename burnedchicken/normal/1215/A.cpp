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
	int a1,a2,k1,k2,n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if(k1>k2) swap(a1,a2),swap(k1,k2);
	cout << max(0,n-(k1-1)*a1-(k2-1)*a2) << ' ';
	if(n<=a1*k1) cout << n/k1 << "\n";
	else cout << a1+(n-a1*k1)/k2 << "\n";
	return 0;
}