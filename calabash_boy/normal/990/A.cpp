#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a,b;
int main(){
    cin>>n>>m>>a>>b;
    if(n%m==0){
        cout<<0<<endl;
        return 0;
    }
    LL q = n%m;
    LL ans = min(q*b,(m-q)*a);
    cout<<ans<<endl;
    return 0;
}