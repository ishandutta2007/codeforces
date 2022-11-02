#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        string str;
        cin>>str;
        string ans=str;
        sort(ans.begin(),ans.end());
        int val=0;
        for(int i=0;i<str.size();++i){
            if(str[i]!=ans[i])++val;
        }
        cout<<val<<'\n';
    }
}