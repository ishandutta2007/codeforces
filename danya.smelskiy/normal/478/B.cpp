#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,a;
int main(){
    cin>>n>>m;
    ans=((n-m+1)*(n-m))/2;
    a=n/m;
    cout<<(((a+1)*(a))/2)*(n%m)+((a*(a-1))/2)*(m-n%m)<<" "<<ans;
}