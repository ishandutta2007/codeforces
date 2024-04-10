#include <bits/stdc++.h>
using namespace std;
string s;
long long ans;
inline long long get(string x){
    long long res=0;
    for (int i=0;i<x.size();++i)
        res=(res*10+(x[i]-'0'));
    return res;
}
int main(){
    cin>>s;
    ans=-1;
    for (int i=1;i<=s.size();++i) {
        string f="";
        for (int j=1;j<=i;++j)
            f+=s[j-1];
        if (f.size()>1 && f[0]=='0') continue;
        if (f.size()>7 )continue;
        for(int j=i+1;j<s.size();++j) {
            string ss="";
            for (int k=i+1;k<=j;++k)
                ss+=s[k-1];
            if(ss.size()>1 && ss[0]=='0') continue;
            if (ss.size()>7) continue;
            string ll="";
            for (int k=j+1;k<=s.size();++k)
                ll+=s[k-1];
            if (ll.size()>1 && ll[0]=='0') continue;
            if (ll.size()>7) continue;
            if (get(f)<=1e6 && get(ss)<=1e6 && get(ll)<=1e6)
            ans=max(ans,get(f)+get(ss)+get(ll));
        }
    }
    cout<<ans;
}