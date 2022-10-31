#include <bits/stdc++.h>
using namespace std;
int n;
int x;
double ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x; ans+=x;
    }
    ans=ans/n;
    cout<<fixed<<setprecision(4)<<ans;
}