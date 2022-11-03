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
    ll n, k;
    cin >> n >> k;
    ll fa = n / 2;
    ll d = fa / (k + (ll)1);
    cout << d << ' ' << d * (ll)k << ' ' << n - d * (k + (ll)1);
}