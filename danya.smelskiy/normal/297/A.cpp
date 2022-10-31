#include <bits/stdc++.h>
using namespace std;

long long ans;
string a,b;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    for (int i=0;i<a.size();++i)
        if (a[i]=='1') ++ans;
    if (ans&1) ++ans;
    for (int i=0;i<b.size();++i)
        if (b[i]=='1') --ans;
    cout<<(ans>=0 ? "YES" : "NO");
}