#include <bits/stdc++.h>
using namespace std;


int n,k;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    int res=(n)*(n-1)/2;
    if (res<=k) cout<<"no solution";
    else {
        for (int i=1;i<=n;++i)
            cout<<"1 "<<i<<'\n';
    }
}