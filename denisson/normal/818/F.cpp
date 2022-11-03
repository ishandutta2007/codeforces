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

int tt;

ll getSum(ll x){
	return x * (ll)(x - 1) / (ll)2;
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
    scanf("%d", &tt);
    while(tt--){
    	int x;
    	scanf("%d", &x);
    	if (x == 1){
    		printf("0\n");
    		continue;
    	}
    	if (x == 2){
    		printf("1\n");
    		continue;
    	}
    	if (x == 3){
    		printf("2\n");
    		continue;
    	}
    	ll ans = x - 1;

    	ll l = 0, r = x;
    	while(l + 1 < r){
    		ll mm = (l + r) >> 1;
    		ll f1 = x - 1 - mm;
    		ll f2 = mm + getSum(mm);
    		if (f1 >= f2)
    			l = mm;
    		else
    			r = mm;
    	}
    	if (l > 1) ans = max(ans, x - 1 + getSum(l));
    	if (r > 1 && x - 1 - r >= r + 1) ans = max(ans, 2 * (ll)(x - 1 - r));

    	//cout << l << ' ' << r << endl;

    	printf("%lld\n", ans);
    }
}