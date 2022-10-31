#include <bits/stdc++.h>
using namespace std;

int n;
long double a[2005];
long long sum;
int kol1;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n+n;++i) {
        string s;
        cin>>s;
        int m=s.size();
        long long z=(s[m-3]-'0')*100+(s[m-2]-'0')*10+(s[m-1]-'0');
        if (!z) ++kol1;
        else sum+=z;
    }
    long double ans=1e9;
    for (int i=max(0,n-kol1);i<=min(n,n+n-kol1);++i){
        long long x=abs(sum-i*1000);
        if (ans>x) ans=x;
    }
    long double ans2=ans;
    ans2/=1000;
    cout<<fixed<<setprecision(3)<<ans2;
}