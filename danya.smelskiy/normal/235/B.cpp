#include <bits/stdc++.h>
using namespace std;
int n;
long double dp1[100005];
long double dp2[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        long double x;
        cin>>x;
        dp1[i]=(dp1[i-1]+1)*x;
        dp2[i]=(dp2[i-1]+(2*dp1[i-1]+1)*x);
    }
    cout<<fixed<<setprecision(6)<<dp2[n];
}