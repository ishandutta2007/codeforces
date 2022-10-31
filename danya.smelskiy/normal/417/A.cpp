#include <bits/stdc++.h>
using namespace std;

int c,d,n,m,k;

int main(){
    cin>>c>>d>>n>>m>>k;
    if (n*m<=k) {
        cout<<0;
        return 0;
    }
    k=n*m-k;
    int ans=k*d;
    ans=min(ans,((k+n-1)/n)*c);
    ans=min(ans,(k/n)*c+(k%n)*d);
    cout<<ans;
}