#include<bits/stdc++.h>
using namespace std;

bool func(const string & s,const string & t){
    int pos=0;
    for(int i=0;i<t.size();i++){
        while(pos<s.size()&&s[pos]!=t[i])pos++;
        if(pos==s.size())return false;
        pos++;
    }
    return true;
}

string s,t;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    cin>>t;
    int ans=0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(func(s.substr(0,i)+s.substr(j+1,s.size()-j-1),t)){
                ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}