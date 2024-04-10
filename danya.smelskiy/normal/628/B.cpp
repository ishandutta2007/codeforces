#include <bits/stdc++.h>
using namespace std;

string s;
long long ans;
int main(){
    cin>>s;
    s="0"+s;
    for (int i=1;i<s.size();++i){
        int x=(s[i-1]-'0')*10+(s[i]-'0');
        if (x%4==0) ans+=i-1;
        if ((s[i]-'0')%4==0) ++ans;
    }
    cout<<ans;
}