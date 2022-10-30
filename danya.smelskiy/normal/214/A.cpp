#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int ans;
int main(){
    cin>>n>>m;
    for (int i=0;i<=sqrt(n);++i){
        x=n-(i*i);
        if (x*x+i==m) ++ans;
    }
    cout<<ans;

}