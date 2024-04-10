#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int cnt[100];


inline bool f(int mid) {
    int kol=0;
    for (int i=0;i<26;++i)
        kol+=(cnt[i]+mid-1)/mid;
    return kol<=n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>n;
    for (int i=0;i<s.size();++i)
        ++cnt[s[i]-'a'];
    int kol=0;
    for (int i=0;i<26;++i)
        if (cnt[i]) ++kol;
    if (kol>n) {
        cout<<"-1";
        return 0;
    }
    int l=1;
    int r=1e9;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (f(mid)) r=mid;
        else l=mid;
    }
    if (f(l)==false) l=r;
    cout<<l<<'\n';
    string res="";
    for (int i=0;i<26;++i) {
        int kol=(cnt[i]+l-1)/l;
        while (kol--) res+=char('a'+i);
    }
    while (res.size()<n) res+='a';
    cout<<res;
}