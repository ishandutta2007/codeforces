#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int x;
int main(){
    cin>>n>>m;
    for (int i=1;i<=sqrt(m);++i){
        if (i>n) break;
        if (m%i==0){
            x=m/i;
            if (m%x==0 && x<=n) ans+=2;
            if (m%x==0 && x<=n && x==i) ans--;
        }
    }
    cout<<ans;
}