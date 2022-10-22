#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,m,a;
    cin >> n >> m >> a;
    long long boys[n],bikes[m];
    for(int i=0; i<n; i++) cin >> boys[i];
    for(int i=0; i<m; i++) cin >> bikes[i];
    sort(boys,boys+n);
    sort(bikes,bikes+m);
    long long l=-1,r=n+1;
    while(r-l>1){
        long long a2=a;
        long long md=(r+l)/2;
        for(int i=0; i<md; i++){
            if(bikes[i]>boys[n-md+i]) a2-=bikes[i]-boys[n-md+i];
        }
        if(a2>=0) l=md;
        else r=md;
    }
    long long result=0;
    for(int i=0; i<l; i++) result+=bikes[i];
    result=max(result-a,0ll);
    cout << l << ' ' << result;
    return 0;
}