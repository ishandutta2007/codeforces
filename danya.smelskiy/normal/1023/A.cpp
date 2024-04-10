#include <bits/stdc++.h>
using namespace std;



int n,m;
string s,ss;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s>>ss;
    int pos=-1;
    for (int i=0;i<n;++i)
        if (s[i]=='*') pos=i;
    if (pos==-1) {
        if (s==ss) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    string s1="",s2="";
    for (int i=0;i<pos;++i)
        s1+=s[i];
    for (int i=pos+1;i<n;++i)
        s2+=s[i];
    if (n-1>m) {
        cout<<"NO";
        return 0;
    }
    string ss1="",ss2="";
    for (int i=0;i<pos;++i)
        ss1+=ss[i];
    for (int i=0;i<s2.size();++i)
        ss2+=(ss[(int)ss.size()-1-i]);
    reverse(ss2.begin(),ss2.end());
    if (s1==ss1 && s2==ss2) cout<<"YES";
    else cout<<"NO";

}