#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e4 + 100;
int a[maxn];
int b[maxn];
long long k;
int n,m;
long long gao(int x,int y){
    int cntx = 0, cnty = 0;
    for (int i=x;i <= n;i ++){
        cntx += a[i] - a[i-x] == x;
    }
    for (int i = y;i <= m;i ++){
        cnty += b[i] - b[i-y] == y;
    }
    return 1ll * cntx * cnty;
}
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i] += a[i-1];
    }
    for (int i=1;i<=m;i++){
        cin>>b[i];
        b[i] += b[i-1];
    }
    long long ans = 0;
    for (int i = 1;i <= n;i ++){
        if (k % i == 0 and k / i <= m){
            ans += gao(i,k/i);
        }
    }
    cout<<ans<<endl;
    return 0;
}