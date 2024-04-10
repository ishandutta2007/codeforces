#include <bits/stdc++.h>
using namespace std;
int n;
int a[2005];
int kol2[2005];
int z[2005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    int kol=0;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        if (i==1 || a[i]!=a[i-1]) {
            ++kol;
            z[kol]=a[i];
        }
        ++kol2[kol];

    }
    for (int i=2;i<=kol;++i) {
        if (kol2[i]==kol2[i-1] && kol2[i]+kol2[i]==n) {
            cout<<"YES"<<'\n';
            cout<<z[i-1]<<" "<<z[i];
            return 0;
        }
    }
    cout<<"NO";
}