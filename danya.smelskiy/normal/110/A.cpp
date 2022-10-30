#include <bits/stdc++.h>
using namespace std;
string s;
int n,ans;
int main(){
    cin>>s;
    for (int i=0;i<s.size();++i)
        if (s[i]=='4' || s[i]=='7') ++ans;
    if (ans==0){
        cout<<"NO";
        return 0;
    }
    while (ans>0){
        if (ans%10!=4 && ans%10!=7){
            cout<<"NO";
            return 0;
        }
        ans/=10;
    }
     cout<<"YES";
}