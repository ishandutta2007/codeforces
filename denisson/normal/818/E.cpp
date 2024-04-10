#include <bits/stdc++.h>
     
using namespace std;
     
typedef unsigned long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
    
 
/*const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }*/

int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int n, k;
int a[100007];
int sum[33][100007];
int uk[33];

int get(int v, int l, int r){
	if (l == 0) return sum[v][r];
	return sum[v][r] - sum[v][l - 1];
}

const bool is_testing = 0;
int main() { 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    } else {
        //freopen("cpr.in", "r", stdin);
        //freopen("cpr.out", "w", stdout);
    }
    scanf("%d %d", &n, &k);
    vector<pair<int, int> > t;
    for (int i = 2; i * i <= k; i++){
    	int kk = 0;
    	while(k % i == 0){
    		k /= i;
    		kk++;
    	}
    	if (kk) t.pub(mp(i, kk));
    }
    if (k != 1) t.pub(mp(k, 1));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < t.size(); i++){
    	int c = t[i].x;
    	for (int j = 0; j < n; j++){
    		while(a[j] % c == 0){
    			a[j] /= c;
    			sum[i][j]++;
    		}
    	}
    	for (int j = 1; j < n; j++) sum[i][j] += sum[i][j - 1];
    }
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int gr = i;
		bool f = 1;
		for (int j = 0; j < t.size(); j++){
			while(uk[j] + 1 <= i && get(j, uk[j] + 1, i) >= t[j].y) uk[j]++;
			gr = min(gr, uk[j]);
			if (get(j, uk[j], i) < t[j].y) f = 0;
		}
		if (f) ans += (ll)gr + 1;
	}

	cout << ans;
}