#include <bits/stdc++.h>
using namespace std;

string s,ss;
bool t1,t2;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    if (s==ss) {
        cout<<"YES";
        return 0;
    }
    if (s.size()!=ss.size() || s.size()==1) {
        cout<<"NO";
        return 0;
    }
    for (int i=0;i<s.size();++i) {
        if (s[i]=='1') t1=true;
        if (ss[i]=='1') t2=true;
    }
    if (t1==t2) cout<<"YES"; else cout<<"NO";
}