#include<bits/stdc++.h>
using namespace std;
int n,k,s,p;
int main(){
    cin>>k>>n>>s>>p;
    cout<<(1LL*k*((n+s-1)/s)+p-1)/p<<endl;
    return 0;
}