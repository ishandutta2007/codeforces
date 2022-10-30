#include <bits/stdc++.h>
using namespace std;
map<char,bool> used;
string s;
int ans;
int main(){
    cin>>s;
    for (int i=1;i<=s.size();++i){
        if (used[s[i-1]]==false){
            used[s[i-1]]=true;
            ++ans;
        }
    }
    if (ans%2==1) cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";
}