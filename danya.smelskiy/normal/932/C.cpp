#include <bits/stdc++.h>
using namespace std;


long long n,a,b;


void rev(int l,int r) {

    for (int i=l+1;i<=r;++i)
        cout<<i<<" ";
    cout<<l<<" ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    if (a>b) swap(a,b);
    if (a==1) {
        for (int i=1;i<=n;++i)
            cout<<i<<" ";
        return 0;
    }
    for (long long i=0;i*a<=n;++i)
    if ((n-i*a)%b==0) {
        for (int j=1;j<=i;++j)
            rev((j-1)*a+1,j*a);
        int l=i*a+1;
        int r=l+b-1;
        while (l<=n) {
            rev(l,r);
            l+=b;
            r+=b;
        }
        return 0;
    }
    cout<<"-1";
}