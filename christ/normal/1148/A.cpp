#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int min (int a, int b) {return a < b ? a : b;}
inline ll min (ll a, ll b) {return a < b ? a : b;}
inline int abs (int a) {return a < 0 ? -a : a;}
int main() {
    int a,b,c;
    scanf ("%d %d %d",&a,&b,&c);
    printf ("%lld\n",2LL*c + min(a,b)*2LL+(a!=b));
    return 0;
}