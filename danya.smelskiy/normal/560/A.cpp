#include <bits/stdc++.h>
using namespace std;
long long n,x,minim;
int main(){
    cin>>n;
    minim=1000000;
    for (int i=1;i<=n;++i){
    cin>>x;
    minim=min(x,minim);}
    if (minim==1) cout<<"-1";
    else cout<<"1";
}