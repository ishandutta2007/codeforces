//  228

#include<bits/stdc++.h>
using namespace std;
#define mod 1000003
int e[10009];
int main(){
    int a,b,c,d,ans=0;
    string s,p="";
    cin>>s;
    e[0]=1;
    for(int i=1;i<=10009;i++){
            e[i]=(e[i-1]*2)%mod;
    }
    for(int i=0;i<s.size();i++){
            if(s[i]=='>')p+="1000";
            else if(s[i]=='<')p+="1001";
            else if(s[i]=='+')p+="1010";
            else if(s[i]=='-')p+="1011";
            else if(s[i]=='.')p+="1100";
            else if(s[i]==',')p+="1101";
            else if(s[i]=='[')p+="1110";
            else p+="1111";
    }
    for(int i=0;i<p.size();i++){
            if(p[i]=='1'){
                    ans+=e[p.size()-i-1];
                    ans%=mod;
            }
    }
    cout<<ans<<endl;
}