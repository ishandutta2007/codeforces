#include <bits/stdc++.h>
using namespace std;
long long n,minim=10000000000,kol,j;
long long x,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x%2==0) ans+=x;
        else {
            ++j;
            kol+=x;
            if (x<minim) minim=x;
        }
    }
    ans+=kol;
    if (j%2==1) ans-=minim;
    cout<<ans;
}