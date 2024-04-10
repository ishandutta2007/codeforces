#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s,t;
    cin>>s;
    if(s.size()==3){
        t="the";
    }else if(s.size()==5){
        t="buffy";
    }else if(s.size()==6){
        t="slayer";
    }else if(s.size()==7){
        t="vampire";
    }else{
        cout<<"none";
        return 0;
    }
    for(int i=0;i<s.size();i++){
        s[i]=(s[i]-'a'+t[i]-'a')%26+'a';
    }
    cout<<s;

    return 0;
}