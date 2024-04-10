#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL read(){
    LL s = 0, ne = 1; char c = getchar();
    for(;c < '0' || c > '9';c = getchar()) if(c == '-') ne = -1;
    for(;c >= '0' && c <= '9';c = getchar()) s = (s << 1) + (s << 3) + c - '0';
    return s * ne;
}
LL T, A, B, C, D;
LL cal(LL a, LL b, LL c, LL d){
    return min(a, b) * min(c, d);
}
int main()
{
 //   freopen("_in.in", "r", stdin);
    T = read();
    while(T--){
        A = read(), B = read(), C = read(), D = read();
        LL ans = max(cal(A, B, C, D), cal(A, C, B, D));
        ans = max(ans, cal(A, D, B, C));
        printf("%lld\n", ans);
    }
    return 0;
}