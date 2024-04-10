#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        while(m--){
            string t;
            for(int i=0;i<s.length();i++){
                char u;
                if(s[i]=='1')u='1';
                else if((i>0&&s[i-1]=='1')+(i+1<s.length()&&s[i+1]=='1')==1)u='1';
                else u='0';
                t+=u;
            }
            if(s==t)break;
            s=t;
        }
        cout<<s<<'\n';
    }
    return 0;
}