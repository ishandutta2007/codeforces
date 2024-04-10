#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[404][404];
vector<int> v[160005];
int kol[160005];
int r[404][404];
int ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        cin>>a[i][j];
    for (int i=n;i>0;--i) {
        for (int j=0;j<=160000;++j)  {
            v[j].clear();
            kol[j]=0;
        }
        for (int j=1;j<=m;++j) {
            r[i][j]=m+1;
            int x=a[i][j];
            if (v[x].size()) {
                int y=v[x][v[x].size()-1];
                r[i][y]=j;
            }
            v[x].push_back(j);
        }
        for (int j=1;j<=m;++j) {
            for (int k=i+1;k<=n;++k) {
                int x=a[k][j];
                while (kol[x]<v[x].size() && v[x][kol[x]]<j) ++kol[x];
                if (kol[x]<v[x].size()){
                    r[k][j]=min(r[k][j],v[x][kol[x]]);
                }
                if (kol[x]) {
                    r[k][v[x][kol[x]-1]]=min(r[k][v[x][kol[x]-1]],j);
                }
            }
        }
        for (int j=i;j<=n;++j) {
            for (int k=m;k>0;--k) {
                if (j>i) r[j][k]=min(r[j][k],r[j-1][k]);
                if (k<m) r[j][k]=min(r[j][k],r[j][k+1]);
                ans=max(ans,(j-i+1)*(r[j][k]-k));
            }
        }
    }
    cout<<ans;
}