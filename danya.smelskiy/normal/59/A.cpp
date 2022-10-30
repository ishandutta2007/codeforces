#include <bits/stdc++.h>
using namespace std;
string s,s1,s2;
int kol1,kol2;
int main(){
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]>='A' && s[i]<='Z'){
            kol1++;
            s1+=s[i]+32;
            s2+=s[i];
        } else {
            kol2++;
            s2+=s[i]-32;
            s1+=s[i];
        }
    }
    if (kol1>kol2) cout<<s2; else cout<<s1;
}