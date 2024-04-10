#include <bits/stdc++.h>
using namespace std;
long long n,k,x,ans;
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>x;
        long long kol=0;
        while (x>0){
            if (x%10==7 || x%10==4) ++kol;
            x/=10;
        }
        if (kol<=k) ++ans;
    }
    cout<<ans;
}