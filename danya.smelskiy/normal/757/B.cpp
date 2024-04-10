#include <bits/stdc++.h>
using namespace std;
long long n,x,ans,kol[1000001];
int main(){
    cin>>n;
    ans=1;
    for (int i=1;i<=n;++i){
        cin>>x;
        for (int j=2;j<=sqrt(x);++j){
            if (x%j==0){
                ++kol[j];
                ans=max(ans,kol[j]);
                while (x%j==0) x/=j;
            }
        }
        if (x>1) { ++kol[x]; ans=max(ans,kol[x]);  }
    }
    cout<<ans;
}