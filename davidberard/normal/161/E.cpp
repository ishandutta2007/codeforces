#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int TT;

int sieve[100100];
vector<int> primes;
void setup() {
    sieve[0] = sieve[1] = 1;
    for(int i=2; i<100000; ++i) {
        if(!sieve[i]) {
            primes.push_back(i);
            for(ll j=(ll) i*i; j<100000; j+=i) {
                sieve[j] =1;
            }
        }
    }
}
int tpow[6] = {1, 10, 100, 1000, 10000, 100000};
int skip = 0;
inline int form(int a, int b, int c, int d, int e) {
    int ans = (a*10000+b*1000+c*100+d*10+e)/tpow[skip];
    //cerr << "!! " << ans << endl;
    return ans;
}

int p;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> TT;
    for(int tt=1; tt<=TT; ++tt) {
        ll ans = 0;
        cin >> p;
        int a = p%10; p/=10;
        int b = p%10; p/=10;
        int c = p%10; p/=10;
        int d = p%10; p/=10;
        int e = p%10; p/=10;
        skip = 0;
        while(!e) {
            ++skip;
            swap(e, d);
            swap(c, d);
            swap(c, b);
            swap(a, b);
        }

        //cerr << " " << e << " " << d << " " << c << " " << b << " " << a << endl;

        for(int x1=0; x1<=9*(skip < 3); ++x1) {
        for(int x2=0; x2<=9*(skip < 2); ++x2) {
        for(int x3=0; x3<=9*(skip < 1); ++x3) {
            int t1 = 0;
            if(skip < 4) {
                for(int d2=0; d2<10; ++d2) {
                    t1+= !sieve[form(d, d2, x1, x2, x3)];
                }
                if(!t1) continue;
            }
        for(int x4=0; x4<=9*(skip < 2); ++x4) {
        for(int x5=0; x5<=9*(skip < 1); ++x5) {
            int t2 = 0;
            if(skip < 3) {
                for(int d3=0; d3<10; ++d3) {
                    t2 += !sieve[form(c, x1, d3, x4, x5)];
                }
                if(!t2) continue;
            }
        for(int x6=0; x6<=9*(skip < 1); ++x6) {
            ll h = 1;
            if(skip < 4) {
                h *= t1;
            }
            if(skip < 3) {
                h *= t2;
            }
            int m = 0;
            if(skip < 2) {
                m = 0;
                for(int d4=0; d4<10; ++d4) {
                    m+= !sieve[form(b, x2, x4, d4, x6)];
                }
                h *= m;
            }
            if(skip < 1) {
                m = 0;
                for(int d5=0; d5<10; ++d5) {
                    m+= !sieve[form(a, x3, x5, x6, d5)];
                }
                h *= m;
            }
            ans += h;
        }}}}}}
        cout << ans << endl;
    }
    return 0;
}