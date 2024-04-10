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
	int q,x,y;
	cin >> q;
	loopi(noob,q){
		int n;
		cin >> n;
		int a[n];
		loop(n) cin >> a[i];
		reverse(a,a+n);
		x=1e9,y=0;
		loop(n){
			if(a[i]<=x){
				x=a[i];
				y++;
			}
		}
		cout << n-y << "\n";
	}
	return 0;
}