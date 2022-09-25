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
	int q,n;
	cin >> q;
	loopi(noob,q){
		cin >> n;
		if(n<4) cout << 4-n << "\n";
		else if(n%2==1) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}