#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        vector<int> v0,v1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                v1.push_back(i);
            }else v0.push_back(i);
        }
        string ans[2];
        ans[0].resize(n);ans[1].resize(n);
        if((v0.size()&1)||s[0]=='0'||s[n-1]=='0')cout<<"NO\n";
        else{
            for(int i=0;i<v0.size();i++){
                ans[i&1][v0[i]]='(';
                ans[~i&1][v0[i]]=')';
            }
            for(int i=0;i<v1.size();i++){
                char ch=(i<v1.size()/2?'(':')');
                ans[0][v1[i]]=ans[1][v1[i]]=ch;
            }
            cout<<"YES\n"<<ans[0]<<'\n'<<ans[1]<<'\n';
        }
    }
    return 0;
}