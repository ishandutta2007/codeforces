#include <bits/stdc++.h>
using namespace std;
string s;
long long ans,k;
int main(){
    cin>>s;
    if (s.size()==1) k=s[0]-'0';
    else {
        k=(s[s.size()-2]-'0')*10+s[s.size()-1]-'0';
    }
    k%=4;
    ans=1+pow(2,k)+pow(3,k)+pow(4,k);
    cout<<ans%5;
}