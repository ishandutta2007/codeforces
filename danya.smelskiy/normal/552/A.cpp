#include <bits/stdc++.h>
using namespace std;
int n,x,x2,y,y2;
long long now,ans;
int a[101][101],b[101][101];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y>>x2>>y2;
        for (int i=x;i<=x2;++i){
            a[i][y]++;
            b[i][y2]++;
        }
    }
    for (int i=1;i<=100;++i){
        now=0;
        for (int j=1;j<=100;++j){
            now+=a[i][j];
            ans+=now;
            now-=b[i][j];
        }
    }
    cout<<ans;
}