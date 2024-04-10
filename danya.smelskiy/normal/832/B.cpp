#include <bits/stdc++.h>
using namespace std;
string s;
bool f[100001];
string ss;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=0;i<s.size();++i) {
        int x=s[i]-'a';
        f[x]=true;
    }
    cin>>s;
    bool t=false;
    for (int i=0;i<s.size();++i)
    if (s[i]=='*') {
        t=true;
        break;
    }
    int n;
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>ss;
        if (t==false && ss.size()!=s.size()) {
            cout<<"NO"<<'\n';
            continue;
        }
        if (t==false) {
            bool res=true;
            for (int j=0;j<ss.size();++j)
            if (s[j]!='?') {
                if (ss[j]!=s[j]) {
                    res=false;
                    break;
                }
            } else {
                int y=ss[j]-'a';
                if (f[y]==false) {
                    res=false;
                    break;
                }
            }
            if (res==false) cout<<"NO";
            else cout<<"YES";
            cout<<'\n';
            continue;
        }
        int l=0;
        if (ss.size()+1<s.size()) {
            cout<<"NO"<<'\n';
            continue;
        }
        bool res=true;
        while (l<ss.size() && l<s.size() && s[l]!='*') {
            if (s[l]=='?') {
                int y=ss[l]-'a';
                if (f[y]==false) {
                    res=false;
                    break;
                }
            } else {
                if (s[l]!=ss[l]) {
                    res=false;
                    break;
                }
            }
            ++l;
        }
        if (res==false) {
            cout<<"NO"<<'\n';
            continue;
        }
        if (l>s.size() || l>ss.size()) {
            if (l==s.size() && l==ss.size()+1) cout<<"YES";
            else cout<<"NO";
            cout<<'\n';
        }
        int ll=s.size()-1;
        int rr=ss.size()-1;
        res=true;
        while (ll+1 && rr+1 && s[ll]!='*') {
            if (s[ll]=='?') {
                int y=ss[rr]-'a';
                if (f[y]==false) {
                    res=false;
                    break;
                }
            } else {
                if (s[ll]!=ss[rr]) {
                    res=false;
                    break;
                }
            }
            --ll; --rr;
        }
        if (res==false) {
            cout<<"NO"<<'\n';
            continue;
        }
        for (int j=l;j<=rr;++j){
            int y=ss[j]-'a';
            if (f[y]) {
                res=false;
                break;
            }
        }
        if (res) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}