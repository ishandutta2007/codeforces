#include <bits/stdc++.h>
using namespace std;
int n,m;
int x;

int main(){
    cin>>n>>m;
    if (n<=2*m) {
        cout<<"-1";
        return 0;
    }
    cout<<n*m<<'\n';
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            x=i+j;
            if (x>n) x-=n;
            cout<<i<<" "<<x<<'\n';
        }
    }
}