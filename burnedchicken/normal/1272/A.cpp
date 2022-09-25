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
	int q;
	cin >> q;
	loopi(noob,q){
		int a[3];
		loop(3) cin >> a[i];
		sort(a,a+3);
		if(a[2]-a[0]<2) cout << "0\n";
		else cout << (a[2]-a[0]-2)*2 << "\n";
	}
	return 0;
}