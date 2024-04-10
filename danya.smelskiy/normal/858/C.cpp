#include <bits/stdc++.h>
using namespace std;

string s;
inline bool ff(char c){
    if (c=='a') return false;
    if (c=='e') return false;
    if (c=='i') return false;
    if (c=='o') return false;
    if (c=='u') return false;
    return true;
}
inline bool f(string s){
    for (int i=2;i<s.size();++i)
        if (ff(s[i-2]) && ff(s[i-1]) && ff(s[i]) && ((s[i-2]!=s[i-1]) || (s[i-1]!=s[i]) || (s[i-2]!=s[i]))) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    string last="";
    for (int i=1;i<=s.size();++i) {
        string nw=last+s[i-1];
        if (f(nw)==false) {
            last=nw;
            continue;
        } else {
            cout<<last;
            cout<<" ";
            last=s[i-1];
        }
    }
    cout<<last;
}