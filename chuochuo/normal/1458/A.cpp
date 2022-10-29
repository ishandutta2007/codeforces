#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,n;
const int maxn=2e5+13;
ll a[maxn],s,b[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<=m;i++) scanf("%lld",&b[i]);
    for (int i=1;i<n;i++) s=__gcd(s,abs(a[1]-a[i+1]));
    for (int i=1;i<=m;i++) printf("%lld ",__gcd(s,a[1]+b[i]));puts("");
    return 0;
}