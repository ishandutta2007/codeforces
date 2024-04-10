#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1005][1005];

int main(){
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        if (m==0) break;
        for (int j=1;j<=n;++j) if (a[i][j]==0){
            if (m==0) break;
            if (m==1) {
                if (i==j) {
                    a[i][j]=1;
                    --m;
                    break;
                }
            } else {
                if (i==j) {
                    --m;
                    a[i][j]=1;
                } else if (m>=2) {
                a[i][j]=1;
                a[j][i]=1;
                m-=2;
                }
            }
        }
    }
    if (m!=0) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
        cout<<a[i][j]<<" ";
        cout<<'\n';
    }
}