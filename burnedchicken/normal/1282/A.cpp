#include <bits/stdc++.h>

#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))

using namespace std;

const int Mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		int a,b,c,r;
		cin >> a >> b >> c >> r;
		if(a>b) swap(a,b);
		int x=c-r;
		int y=c+r;
		if(x<=a&&y>=b) cout << "0\n";
		else if(x>=b||y<=a) cout << b-a << "\n";
		else if(x<=a&&y<b) cout << b-y << "\n";
		else if(x>a&&y>=b) cout << x-a << "\n";
		else cout << b-a+x-y << "\n";
	}
	return 0;
}