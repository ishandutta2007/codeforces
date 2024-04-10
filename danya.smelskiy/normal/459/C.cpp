#include <bits/stdc++.h>
using namespace std;


long long n,k,d;
int ans[1005][1005];
int q[1005];

int all;
void recurs(int sz) {
    if (sz==d) {
        ++all;
        for (int i=1;i<=d;++i)
            ans[i][all]=q[i];
        if (all==n) {
            for (int i=1;i<=d;++i) {
                for (int j=1;j<=n;++j)
                    cout<<ans[i][j]<<" ";
                cout<<'\n';
            }
            exit(0);
        }
        return;
    }
    for (int i=1;i<=k;++i) {
        q[sz+1]=i;
        recurs(sz+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>d;
    long long z=1;
    for (int i=1;i<=d;++i) {
        z*=k;
        if (z>=n) break;
    }
    if (z<n) {
        cout<<"-1";
        return 0;
    }
    recurs(0);
}