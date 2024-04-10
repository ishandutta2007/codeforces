#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n,m;
        cin>>n>>m;
        string str;
        cin>>str;
        string output(str.size(),'0');
        vector<int> left(str.size(),0),right(str.size(),0);
        int li=-1'000'000'000'000ll;
        for(int i=0;i<str.size();++i){
            if(str[i]=='1')li=i;
            left[i]=li;
        }
        int ri=1'000'000'000'000ll;
        for(int i=str.size()-1;i>=0;--i){
            if(str[i]=='1')ri=i;
            right[i]=ri;
        }
        for(int i=0;i<str.size();++i){
            if(str[i]=='1')output[i]='1';
            else if(i-left[i]==right[i]-i)output[i]='0';
            else if(i-left[i]<=m||right[i]-i<=m)output[i]='1';
            else output[i]='0';
        }
        cout<<output<<'\n';
    }
}