#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
string a[100001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
                bool t=false;
            for (int k=1;k<=n;++k) if (i!=k){
                if (a[i][j-1]<a[k][j-1]){
                    t=true;
                    break;
                }
            }
            if (t==false){
                    ++ans;
                    //cout<<i<<" "<<j<<endl;
                    break;
                }
        }
    }
    cout<<ans;
}