#include <bits/stdc++.h>
using namespace std;
int main(){
    long long res=1;
    long long n,m;
    cin>>n>>m;
    for (long long i=n+1;i<=m;++i) {
        if (i%(long long)10==0) {
            cout<<"0";
            return 0;
        }
        res=(res*i)%10;
    }
    cout<<res;
}