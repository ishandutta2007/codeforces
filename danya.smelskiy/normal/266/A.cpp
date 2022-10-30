#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
char last;
int main(){
    cin>>n;
    cin>>s;
    for (int i=0;i<n;++i){
        if (s[i]==last) ++ans;
        else last=s[i];
    }
    cout<<ans;
}