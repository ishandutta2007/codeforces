#include <bits/stdc++.h>
using namespace std;


int n,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if (k>(n*n+1)/2) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (k==0 || (i%2==1 && j%2==0) || (i%2==0 && j&1)) cout<<"S";
            else { --k; cout<<"L"; }
        }
        cout<<'\n';
    }
}