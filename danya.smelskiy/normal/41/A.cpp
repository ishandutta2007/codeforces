#include <bits/stdc++.h>
using namespace std;
string s,s2;
int main(){
    cin>>s;
    cin>>s2;
    reverse(s2.begin(),s2.begin()+s2.size());
    if (s==s2) cout<<"YES";
    else cout<<"NO";
}