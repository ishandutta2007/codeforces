#include <bits/stdc++.h>
using namespace std;


int n,m;
int a[55][55];
bool t=false;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            cin>>a[i][j];
            if (a[i][j]) {
                if (i==1) t=true;
                else if (i==n) t=true;
                if (j==1) t=true;
                else if (j==m) t=true;
            }
        }
    }
    if (t) cout<<2;
    else cout<<4;
}