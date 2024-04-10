#include <bits/stdc++.h>
using namespace std;

int n,m;
string s,ss;
bool used[100005];
vector<int> v,vv;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    m=n-m;
    cin>>s>>ss;
    for (int i=0;i<s.size();++i)
        if (s[i]!=ss[i]) vv.push_back(i);
        else v.push_back(i);
    string res=s;
    if (v.size()>m) {
        for (int i=0;i<m;++i)  {
            int x=v[i];
            used[x]=true;
        }
    } else {
        for (int i=0;i<v.size();++i) {
            int x=v[i];
            used[x]=true;
        }
        m-=v.size();
        if ((n-v.size())<2*m) {
            cout<<"-1";
            return 0;
        }
        int kol=0;
        for (int i=0;i<res.size();++i) if (used[i]==false) {
            ++kol;
            if (kol>2*m) break;
            if (kol<=m) res[i]=s[i];
            else res[i]=ss[i];
            used[i]=true;
        }
    }
    for (int i=0;i<n;++i)
        if (used[i]==false)
            for (int j=0;j<26;++j)
    if (s[i]-'a'!=j && ss[i]-'a'!=j) {
        res[i]=char(j+'a');
        break;
    }
    cout<<res;
}