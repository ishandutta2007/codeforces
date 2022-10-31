#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int ans;
int a[200005];
vector<int> v[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    for (int i=1;i<=m;++i) if (v[i].size()) {
        int l=0;
        for (int j=0;j<v[i].size();++j) {
            int y=v[i][j];
            while (l<j) {
                int x=v[i][l];
                if (y-x+1-(j-l+1)>k) ++l;
                else break;
            }
            int x=v[i][l];
            if (y-x+1-(j-l+1)<=k) ans=max(ans,j-l+1);
        }
    }
    cout<<ans;
}