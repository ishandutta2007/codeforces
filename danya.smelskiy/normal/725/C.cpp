#include <bits/stdc++.h>
using namespace std;


string s;
bool used[500];
pair<int,int> pos[500];

inline void check(string s,string ss) {
    int x=1,y=1;
    for (int i=1;i<=s.size();++i) {
        pos[s[i-1]]=make_pair(x,y);
        if (x==1) {
            if (y==13) x=2,y=13;
            else ++y;
        } else --y;
    }
    for (int i=1;i<ss.size();++i) {
        x=abs(pos[ss[i]].first-pos[ss[i-1]].first);
        y=abs(pos[ss[i]].second-pos[ss[i-1]].second);
        if (x>1 || y>1) return;
    }
    for (int i=1;i<=13;++i)
        cout<<s[i-1];
    cout<<'\n';
    for (int i=26;i>13;--i)
        cout<<s[i-1];
    exit(0);
}

int main() {
    string ss="";
    cin>>s;
    for (int i=1;i<s.size();++i)
    if (s[i]==s[i-1]) {
        cout<<"Impossible";
        return 0;
    }
    for (int i=0;i<s.size();++i)
    if (used[s[i]]==false) {
        ss+=s[i];
        used[s[i]]=true;
    }
    for (int i=0;i<26;++i) {
        check(ss,s);
        string sk="";
        for (int i=1;i<ss.size();++i)
            sk+=ss[i];
        sk+=ss[0];
        ss=sk;
    }
    cout<<"Impossible";
}