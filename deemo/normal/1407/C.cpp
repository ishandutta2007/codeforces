#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 1e6 + 10;

int ar[MAXN];

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "! 1" << endl;
        return;
    }

    memset(ar, -1, sizeof(ar));
    int big = 1;
    cout << "? 1 2" << endl;
    int a; cin >> a;
    cout << "? 2 1" << endl;
    int b; cin >> b;
    if (a > b)
        big = 2;
    else
        big = 1;
    int other = 1+2-big;
    ar[other] = max(a, b);
    for (int i = 3; i <= n; i++) {
        cout << "? " << big << " " << i << endl;
        cin >> a;
        cout << "? " << i << " " << big << endl;
        cin >> b;

        other = a<b? i: big;
        big = i+big-other;
        ar[other] = max(a, b);
    }

    for (int i = 1; i <= n; i++)
        if (ar[i] == -1)
            ar[i] = n;

    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << ar[i] << " ";
    cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}