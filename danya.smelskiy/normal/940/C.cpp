#include <bits/stdc++.h>
using namespace std;


int n,m;
string s;
bool used[10005];


inline string solve(string s) {
    string res="";
    for (int i=m;i>0;--i) {
        bool t=false;
        for (char j=s[i-1]+1;j<='z';++j) if (used[j]) {
            for (int k=1;k<i;++k)
                res+=s[k-1];
            res+=j;
            char pos;
            for (char k='a';k<='z';++k)
            if (used[k]) {
                pos=k;
                break;
            }
            for (int k=i+1;k<=m;++k)
                res+=pos;
            return res;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<s.size();++i)
        used[s[i]]=true;
    if (m<=n) {
        cout<<solve(s);
        return 0;
    }
    string res=s;
    char pos;
    for (char i='a';i<='z';++i)
    if (used[i]) {
        pos=i;
        break;
    }
    for (int i=n+1;i<=m;++i)
        res+=pos;
    cout<<res;
}