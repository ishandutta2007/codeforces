#include <bits/stdc++.h>
using namespace std;

int n,ans,kol[30];
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=1;i<n;++i) {
        int x=s[i*2-2]-'a';
        ++kol[x];
        x=s[i*2-1]-'A';
        if (kol[x]==0) ++ans;
        else --kol[x];
    }
    cout<<ans;
}