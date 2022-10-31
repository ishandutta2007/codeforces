#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    cin>>n>>m;
    if (n==0 && m==0) cout<<"NO";
    else
    if (n==m) cout<<"YES";
    else if (abs(n-m)==1) cout<<"YES";
    else cout<<"NO";
}