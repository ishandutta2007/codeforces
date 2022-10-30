#include <bits/stdc++.h>
using namespace std;
int n,a,b,ans;
int main(){
    cin>>n>>a>>b;
    cout<<n-max(n-b,a+1)+1;
}