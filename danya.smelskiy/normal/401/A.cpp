#include <bits/stdc++.h>
using namespace std;
long long n,m,x,ans,k;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>x;
        ans+=x;
    }
    x=abs(ans);
    while (x>0){
        if (x>m) x-=m;
        else x=0;
        k++;
    }
    cout<<k;
}