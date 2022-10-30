#include <bits/stdc++.h>
using namespace std;
int a[5];
string s;
long long ans;
int main(){
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    cin>>s;
    for (int i=0;i<s.size();++i){
        ans+=a[s[i]-'0'];
    }
    cout<<ans;
}