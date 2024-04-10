#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define LL long long
const int CN = 1e5 + 10;
int read(){
    int s = 0, ne = 1; char c = getchar();
    for(;c < '0' || c > '9';c = getchar()) if(c == '-') ne = -1;
    for(;c >= '0' && c <= '9';c = getchar()) s = (s << 1) + (s << 3) + c - '0';
    return s * ne;
}
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int T, n, u[CN], v[CN]; map<pair<int, int>, int> cnt; 
int main()
{
 //   freopen("_in.in", "r", stdin);
    T = read(); while(T--){
        n = read(), cnt.clear(); LL ans = 0;
        for(int i = 1; i <= n; i++){
            int a = read(), b = read(), c = read(), d = read(), g;
            u[i] = c - a, v[i] = d - b;
            if(!u[i]) v[i] = v[i] < 0 ? -1 : 1;
            else if(!v[i]) u[i] = u[i] < 0 ? -1 : 1;
            else {
                g = gcd(abs(u[i]), abs(v[i]));
                u[i] /= g, v[i] /= g;
            }
            ans += cnt[mp(-u[i], -v[i])];
            cnt[mp(u[i], v[i])]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}