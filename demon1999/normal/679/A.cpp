#include <bits/stdc++.h> 

using namespace std; 
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define gi get_int()
typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll cnn = 800, md = 1000000007, sz_g = 200000, pq = 100000000, inf = 1000000000LL,
 mod2 = 5000000, ma = 128 * 1024, ma1 = 8;

int get_int() {
	int a;
	scanf("%d", &a);
	re a;
}
void my_assert(bool ok) {
	if (!ok) while(true);	
}

int n;

int main(){
    iostream::sync_with_stdio(0);
    //freopen("sum.in", "r", stdin);
    //freopen("sum.out", "w", stdout);
   	int a[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};
   	int an = 0;
   	forn (i, 19) {
   		cout << a[i] << "\n";
   		cout.flush();
   		string k;
   		cin >> k;
   		if (k[0] == 'y') an++;
   	}
   	if (an < 2) {
   		cout << "prime\n";
   		cout.flush();
   	}
   	cout << "composite\n";
   	cout.flush();
    return 0;
}