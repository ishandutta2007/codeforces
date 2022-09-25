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
		int n,k1,k2;
		cin >> n >> k1 >> k2;
		int a;
		loop(k1){
			cin >> a;
			if(a==n){
				cout << "YES\n";
			}
		}
		loop(k2){
			cin >> a;
			if(a==n){
				cout << "NO\n";
			}
		}
	}
	return 0;
}