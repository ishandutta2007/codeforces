#include <bits/stdc++.h>
using namespace std;


string s,ss;
int kol1[1000],kol2[1000];
int kol;

inline bool f(int mid){
    int k=0;
    for (int i=0;i<26;++i)
    if (kol2[i] && kol1[i]<kol2[i]*mid) {
        k+=kol2[i]*mid-kol1[i];
    }
    return k<=kol;
}
int main(){
    ///
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='?') ++kol; else
        ++kol1[s[i]-'a'];
    }
    for (int i=0;i<ss.size();++i) {
        ++kol2[ss[i]-'a'];
    }
    int l=0;
    int r=(int)(s.size())/((int)(ss.size()))+100;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (f(mid)) l=mid;
        else r=mid;
    }
    if (f(r)) l=r;
    for (int i=0;i<s.size();++i) if (s[i]=='?') {
        bool t=false;
        for (int j=0;j<26;++j)
        if (kol1[j]<kol2[j]*l) {
            t=true;
            ++kol1[j];
            s[i]=char('a'+j);
            break;
        }
        if (t==false) s[i]='a';
    }
    cout<<s;
}