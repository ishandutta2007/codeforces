#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
int main(){
    cin>>n>>m;
    m=min(m,n/2);
    long long y=n-m-m;
    ans=m*(m+y)+y*m;
    ans=ans+(m)*(m-1);
    cout<<ans;
}