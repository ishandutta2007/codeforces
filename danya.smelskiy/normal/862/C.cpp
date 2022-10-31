#include <bits/stdc++.h>
using namespace std;


int n,m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (n==2 && m==0) {
        cout<<"NO";
        return 0;
    }
    if (n==1) {
        cout<<"YES"<<'\n'<<m;
        return 0;
    }
    int z=(1<<17);
    if (n==2) {
        cout<<"YES"<<'\n';
        cout<<z<<" "<<(z+m);
        return 0;
    }
    cout<<"YES"<<'\n';
    int x=0;
    for (int i=1;i<=n-3;++i){
        cout<<i<<" ";
        x^=i;
    }
    if (x==m) cout<<z<<" "<<(z<<1)<<" "<<z+(z<<1);
    else cout<<"0 "<<z<<" "<<(z^x^m);
}