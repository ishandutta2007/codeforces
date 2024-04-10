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
		int n;
		cin >> n;
		int a[n];
		loop(n) cin >> a[i];
		bool ok=false;
		int x;
		loop(n-1){
			if(abs(a[i+1]-a[i])>1){
				ok=true;
				x=i;
				break;
			}
		}
		if(ok){
			cout << "YES\n";
			cout << x+1 << ' ' << x+2 << "\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}