#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin>>s;
    for (int i=1;i<=s.size();++i){
        if (s[i-1]=='H' || s[i-1]=='Q' || s[i-1]=='9') { cout<<"YES"; return 0;}
    }
    cout<<"NO";
}