#include <bits/stdc++.h>
using namespace std;


int n;
int a[2005];
int ans;
int kol;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        int res=1;
        for (int j=2;j<=sqrt(a[i]);++j) if (a[i]%j==0){
            res*=j;
            while (a[i]%j==0) a[i]/=j;
        }
        if (a[i]>1) res*=a[i];
        a[i]=res;
        if (a[i]==1) ++kol;
    }
    if (kol) {
        cout<<n-kol;
        return 0;
    }
    int res=1e9;
    int xx1,xx2;
    for (int i=1;i<=n;++i) {
        int x=a[i];
        for (int j=i+1;j<n;++j) {
            x=__gcd(a[j],x);
            if (x==1) {
                if (j-i<res) {
                    res=j-i;
                    xx1=i;
                    xx2=j;
                }
                break;
            }
        }
        x=a[i];
        for (int j=i-1;j>0;--j) {
            x=__gcd(a[j],x);
            if (x==1) {
                if (i-j<res) {
                    res=i-j;
                    xx1=i;
                    xx2=j;
                }
                break;
            }
        }
    }
    if (res==1e9) {
        cout<<"-1";
        return 0;
    }
    cout<<res+n-1;
}