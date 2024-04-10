#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;
using db=double;
__attribute__((always_inline))
inline db cal(db a,db b,db c,db d,db e,db f,db g,db h,db i){
    double z=(a*(e*i-f*h)-b*(d*i-f*g)-c*(e*g-d*h));
    return abs(z*z/(2*(a*e-b*d)*(a*h-b*g)*(d*h-e*g)));
}
db A[3005],B[3005],C[3005];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;cin>>n;
    rep(i,n)cin>>A[i]>>B[i]>>C[i];
    double s=0;
    rep(i,n)iter(j,i+1,n)iter(k,j+1,n)
        s+=cal(A[i],B[i],C[i],A[j],B[j],C[j],A[k],B[k],C[k]);
    cout<<fixed<<setprecision(10)<<(s/(1ll*n*(n-1)*(n-2)/6))<<endl;
}