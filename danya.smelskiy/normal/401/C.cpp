#include <bits/stdc++.h>
using namespace std;


int n,m;
int kol[2000005];
int sz;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (n-1==m) {
        int it=0;
        while (n || m) {
            if (it&1) { --m; cout<<"1"; }
            else { --n; cout<<"0";}
            ++it;
        }
        return 0;
    }
    if (n>m) {
        cout<<"-1";
        return 0;
    }
    swap(n,m);
    while (true) {
        ++sz;
        if (sz&1) {
            if (n) {
            --n;
            kol[sz]=1;
            }
        } else {
            if (!m) {
                --sz;
                break;
            }
            --m;
        }
    }
    if (n<0) {
        cout<<"-1";
        return 0;
    }
    int last=1;
    for (int i=1;i<=n;++i) {
        ++kol[last];
        if (kol[last]>2) {
            cout<<"-1";
            return 0;
        }
        last+=2;
        if (last>sz) last=1;
    }
    for (int i=1;i<=sz;++i) {
        if (i&1) for (int j=1;j<=kol[i];++j) cout<<"1";
        else cout<<"0";
    }
}