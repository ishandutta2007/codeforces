#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    if (n==1) cout<<1;
    else if (m-1<n-m) cout<<m+1;
    else cout<<m-1;
}