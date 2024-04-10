#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<string,int> kol;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        char c;
        cin>>c; cin>>s;
        string ss="";
        for (int i=18;i>s.size();--i)
            ss+="0";
        string sk="";
        for (int i=0;i<s.size();++i) {
            int x=s[i]-'0';
            if (x%2==0) sk+="0";
            else sk+="1";
        }
        ss+=sk;
        if (c=='+') ++kol[ss];
        else if (c=='-') --kol[ss];
        else cout<<kol[ss]<<'\n';
    }
}