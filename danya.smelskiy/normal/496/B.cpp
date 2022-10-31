#include <bits/stdc++.h>
using namespace std;


int n;
string s,res;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    res=s;
    for (int i=0;i<s.size();++i) {
        int kol=10-(s[0]-'0');
        for (int j=0;j<s.size();++j) {
            int x=s[j]-'0'+kol;
            x%=10;
            s[j]=char(x+'0');
        }
        res=min(res,s);
        string ss="";
        ss+=s[n-1];
        for (int i=0;i<n-1;++i)
            ss+=s[i];
        s=ss;
    }
    cout<<res;
}