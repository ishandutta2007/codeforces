#include <bits/stdc++.h>
using namespace std;



int n,m,tp;
int a[1005][105];
int b[1005][105];
vector<pair<int,int> > ans;

inline bool f(int x,int y) {
    if (tp) swap(x,y);
    ans.push_back(make_pair(x,y));
    for (int i=1;i<=n;++i)
        if (a[i][x]>a[i][y]) swap(a[i][x],a[i][y]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>tp;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
        sort(b[i]+1,b[i]+m+1);
        if (tp==1) reverse(b[i]+1,b[i]+m+1);
    }
    for (int j=1;j<=m;++j) {
        for (int i=1;i<=n;++i)
        if (a[i][j]!=b[i][j]) {
            for (int k=j+1;k<=m;++k)
            if (a[i][k]==b[i][j]) {
                f(j,k);
                break;
            }
        }
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}