#include <bits/stdc++.h>
using namespace std;


int n;
string s;
int cnt[1000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=0;i<s.size();++i) {
        ++cnt[s[i]-'a'];
    }
    if (n==1) {
        cout<<"Yes";
        return 0;
    }
    bool t=false,tt=false;
    for (int i=0;i<26;++i)
        if (cnt[i]==1) t=true;
        else if (cnt[i]>1) tt=true;
    if (t==false || (t==true && tt==true)) cout<<"Yes";
    else cout<<"No";
}