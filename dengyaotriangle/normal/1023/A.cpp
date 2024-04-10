#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!


int main(){
    int n,m;cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int pos=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='*'){pos=i;break;}
    }
    bool ans;
    if(pos==-1) ans=s==t;
    else{
        string a=s.substr(0,pos);
        string b=s.substr(pos+1);
        ans=s.size()-1<=t.size()&&a==t.substr(0,pos)&&b==t.substr(t.size()-(s.size()-pos-1));
    }
    cout<<(ans?"YES":"NO");
    return 0;
}