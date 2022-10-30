#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
bool used[100005];



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m;
    cin>>s;
    n=s.size();
    s="#"+s;
    string res="";
    for (int i=0;i<26;++i) {
        int last=n+1;
        int lastm=n+n;
        bool t=false;
        for (int j=n;j>0;--j) {
            if (used[j]) last=j;
            if (s[j]-'a'==i) lastm=j;
            if (last-j>=m) {
                if (lastm-j>=m) {  t=true;}
                else {
                    used[lastm]=true;
                    last=lastm;
                }
            }
        }
        for (int j=1;j<=n;++j) {
            if (t && s[j]-'a'==i) used[j]=true;
            if (used[j] && s[j]-'a'==i) res+=char(i+'a');
        }
        if (!t) break;
    }
    cout<<res;
}