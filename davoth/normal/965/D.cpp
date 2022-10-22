#include <bits/stdc++.h>
using namespace std;
/*bool check(long long n){
    long long m1=m;
    if(b*n>bn) m1-=(b*n-bn)*pb;
    if(s*n>sn) m1-=(s*n-sn)*ps;
    if(c*n>cn) m1-=(c*n-cn)*pc;
    return m1 >= 0;
}*/
int main() {
    int w,l;
    cin >> w >> l;
    int a[w],ans=INT_MAX;
    for(int i=1; i<w; i++){
        cin >> a[i];
        a[i]+=a[i-1];
        if(i>=l) ans=min(ans,a[i]-a[i-l]);
    }
    cout << ans;
    return 0;
}