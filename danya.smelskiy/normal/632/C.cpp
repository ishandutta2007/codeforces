#include <bits/stdc++.h>
using namespace std;
string s[500001];
int n;
bool cmp(string s,string s1){
    return (s+s1<s1+s);
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>s[i];
    sort(s+1,s+n+1,cmp);
    for (int i=1;i<=n;++i)
        cout<<s[i];
}