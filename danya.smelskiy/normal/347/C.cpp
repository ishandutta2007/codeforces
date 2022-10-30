#include <bits/stdc++.h>
using namespace std;

int n,x,res;
int mx;

int main(){
    //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        if (i==1) res=x;
        else res=__gcd(res,x);
        mx=max(mx,x);
    }
    if ((mx/res-n)%2==1) cout<<"Alice";
    else cout<<"Bob";
}