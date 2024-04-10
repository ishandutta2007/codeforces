#include <bits/stdc++.h>
using namespace std;
string s;
long long last,ans;
int main(){
    cin>>s;
    last=0;
    for (int i=0;i<s.size();++i){
            if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y'){
                ans=max(ans,i+1-last);
                last=i+1;
            }
    }
    ans=max(ans,s.size()+1-last);
    cout<<ans;
}