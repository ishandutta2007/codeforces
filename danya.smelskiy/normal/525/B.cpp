#include <bits/stdc++.h>
using namespace std;

string s;
int n,x;
int kol[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        ++kol[x];
        --kol[s.size()-x+2];
    }
    int last=0;
    for (int i=1;i<=s.size();++i) {
        last+=kol[i];
        if (last%2==0) cout<<s[i-1];
        else cout<<s[s.size()-i];
    }
}