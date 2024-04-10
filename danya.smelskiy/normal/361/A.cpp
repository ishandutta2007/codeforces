#include <bits/stdc++.h>
using namespace std;

int n,k;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (i==j) cout<<k<<" ";
            else cout<<"0 ";
        }
        cout<<'\n';
    }
}