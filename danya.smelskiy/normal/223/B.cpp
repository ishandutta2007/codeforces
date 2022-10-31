#include <bits/stdc++.h>
using namespace std;


string s,ss;
int p[200005];
int last[200005][27];
int last2[300];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    int n=s.size();
    int m=ss.size();
    int l=0;
    for (int i=1;i<=n;++i){
        for (int j=0;j<26;++j)
            last[i][j]=last[i-1][j];
        if (l<m && ss[l]==s[i-1]) {
            ++l;
            last[i][s[i-1]-'a']=l;
        }
    }
    l=0;
    reverse(ss.begin(),ss.end());
    for (int i=n;i>0;--i) {
        if (l<m && ss[l]==s[i-1]) {
            ++l;
            last2[s[i-1]-'a']=l;
        }
        bool t=false;
        for (int j=0;j<26;++j)
            if ((last[i-1][j]+last2[s[i-1]-'a']>=m && last2[s[i-1]-'a']) || (last[i-1][s[i-1]-'a']+last2[j]>=m && last[i-1][s[i-1]-'a'])) {
                t=true;
                break;
            }
        if (!t) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}