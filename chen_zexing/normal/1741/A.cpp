#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        string a,b;
        map <char,int> mp;
        mp['S']=0,mp['M']=1,mp['L']=2;
        cin>>a>>b;
        if(mp[a[a.size()-1]]>mp[b[b.size()-1]]) puts(">");
        else if(mp[a[a.size()-1]]<mp[b[b.size()-1]]) puts("<");
        else{
            if(a.size()>b.size()) puts(a[a.size()-1]=='S'?"<":">");
            else if(a.size()<b.size()) puts(a[a.size()-1]=='S'?">":"<");
            else puts("=");
        }
    }
    return 0;
}