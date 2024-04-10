#include <bits/stdc++.h>
using namespace std;

string s,s1,s2;
int kol[30],kol2[30],kol3[30],kol4[30];
int ans,x,y;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>s1>>s2;
    for (int i=0;i<s.size();++i)
        ++kol[s[i]-'a'];
    for (int i=0;i<s1.size();++i)
        ++kol2[s1[i]-'a'];
    for (int i=0;i<s2.size();++i)
        ++kol3[s2[i]-'a'];
    for (int i=0;i<=s.size();++i) {
        bool t=false;
        int z=1e9;
        for (int j=0;j<26;++j) {
            kol4[j]=kol[j]-(kol2[j]*i);
            if (kol4[j]<0) {
                t=true;
                break;
            }
            if (kol3[j]) z=min(z,kol4[j]/kol3[j]);
        }
        if (t) break;
        if (i+z>ans) {
            ans=i+z;
            x=i;
            y=z;
        }
    }
    for (int i=1;i<=x;++i)
        cout<<s1;
    for (int i=1;i<=y;++i)
        cout<<s2;
    for (int i=0;i<26;++i) {
        kol[i]-=kol2[i]*x+kol3[i]*y;
        while (kol[i]--) cout<<char('a'+i);
    }
}