#include <bits/stdc++.h>
using namespace std;

string s,ss,res;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    res=s;
    for (int i=0;i<s.size();++i) if (s[i]!=ss[i]) {
        if (ss[i]>s[i]) {
            cout<<"-1";
            return 0;
        }
        res[i]=ss[i];
    }
    cout<<res;
}