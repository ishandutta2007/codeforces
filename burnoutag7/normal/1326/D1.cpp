#include<bits/stdc++.h>
using namespace std;

bool palin(string s){
    int len=s.size();
    for(int i=0;i+i+1<len;i++){
        if(s[i]!=s[len-i-1])return false;
    }
    return true;
}

string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>s;
        int l=0,r=s.size()-1;
        while(s[l]==s[r]&&l<r){
            l++;
            r--;
        }
        string res;
        for(int i=r;i>=l;i--){
            if(palin(s.substr(l,i-l+1))){
                res=s.substr(l,i-l+1);
                break;
            }
        }
        for(int i=l;i<=r&&r-i+1>res.size();i++){
            if(palin(s.substr(i,r-i+1))){
                res=s.substr(i,r-i+1);
                break;
            }
        }
        cout<<s.substr(0,l)+res+s.substr(r+1,s.size()-r)<<endl;
    }

    return 0;
}