#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[505][505];

inline int get(int x,int y,int xx,int yy){
    return a[xx][yy]+a[x-1][y-1]-a[xx][y-1]-a[x-1][yy];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            cin>>a[i][j];
            a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        }
    }
    int ans=-2e9;
    for (int i=2;i<n;++i) {
        for (int j=2;j<m;++j) {
            int last=get(i-1,j-1,i+1,j+1)-get(i,j,i,j)-get(i,j-1,i,j-1);
            ans=max(ans,last);
            int l1=i-2;
            int r1=j-2;
            int l2=i+2;
            int r2=j+2;
            while (l1>0 && r1>0 && l2<=n && r2<=m) {
                last=get(l1,r1,l2,r2)-last-get(l1+1,r1,l1+1,r1);
                ans=max(ans,last);
                ++l2; ++r2; --l1; --r1;
            }
        }
    }
    cout<<ans;
}