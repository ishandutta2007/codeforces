 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	if(n % 2 == 0) {
		vll ans(n);
		M00(i, n-1) {
			cout << "? " << i+1  << " " << i + 2 << endl;
			cout.flush();
			cin >> ans[i];
		}
		cout << "? " << 1 << " " << 3 << endl;
		cout.flush();
		cin >> ans[n-1];
		vll cage(n);
		cage[2] = ans[n-1] - ans[0];
		cage[1] = -(cage[2] - ans[1]);
		cage[0] = -(cage[1] - ans[0]);
		M00(i, n-3) {
			cage[i+3] = ans[i+2] - cage[i+2];
		}
		cout << "! ";
		M00(i, n)  {
			cout << cage[i] << " ";
		}
		
	} else {
		vll ans(n);
		M00(i, n-1) {
			cout << "? " << i+1  << " " << i + 2 << endl;
			cout.flush();
			cin >> ans[i];
		}
		cout << "? " << 1 << " " << n << endl;
		cout.flush();
		cin >> ans[n-1];

		ll sum = ans[n-1];
		M00(i, n/2) {
			sum -= ans[2*i];
		}
		vll cage(n);
		cage[n-1] = sum;
		dbg(sum);
		for(int i = n-2; i >= 0; i--) {
			cage[i] = ans[i] - cage[i+1];
		}
		cout << "! ";
		M00(i, n)  {
			cout << cage[i] << " ";
		}
	}
}