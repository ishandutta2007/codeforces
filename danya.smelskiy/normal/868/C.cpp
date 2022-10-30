#include <bits/stdc++.h>
using namespace std;
int n,m;
int kol[100005];
int dp[5];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        int msk=0;
        for (int j=0;j<m;++j) {
            int x;
            cin>>x;
            if (x) msk|=(1<<j);
            if (x) ++dp[j];
        }
        ++kol[msk];
    }
    int kol2=n;
    for (int i=n;i>0;--i) {
        int msk=0;
        for (int j=0;j<m;++j)
            if (dp[j]>(kol2)/2) msk|=(1<<j);
        if (!msk) {
            cout<<"YES";
            return 0;
        }
        int mx1=-1;
        int mx2=0;
        int pos=0;
        for (int j=0;j<(1<<m);++j)
        if (kol[j]) {
            int nw1=0,nw2=0;
            for (int k=0;k<m;++k)
            if (j&(1<<k)) {
                if (msk&(1<<k)) ++nw1;else ++nw2;
            }
            if (nw1>mx1 || (nw1==mx1 && nw2>mx2)) {
                mx1=nw1;
                mx2=nw2;
                pos=j;
            }
        }
        --kol2;
        --kol[pos];
        for (int j=0;j<m;++j) {
            if (pos&(1<<j)) --dp[j];
        }
    }
    cout<<"NO";
}