#include <bits/stdc++.h>
using namespace std;

map<string,bool> used;
string s;
string last;
int ans;
int main(){
    getline(cin,s);
    for (int i=1;i<s.size()-1;++i){
        if (s[i]==',') {if (used[last]==false) ++ans; used[last]=true; last="";}
        else if (s[i]>='a' && s[i]<='z') last=last+s[i];
    }
    if (used[last]==false && last.size()!=0) ++ans;
    cout<<ans;
}