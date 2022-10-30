#include <bits/stdc++.h>
using namespace std;
int n,x,ans,kol[1000001];

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        ++kol[x];
        if (kol[x]>kol[ans]) {
            ans=x;
        }
    }
    cout<<ans;
}