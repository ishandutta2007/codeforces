#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
int main(){
    cin>>n;
    cin>>s;
    for (int i=1;i<=n;++i)
        cin>>s;
    if (n%2==1) cout<<"contest";
    else cout<<"home";
}