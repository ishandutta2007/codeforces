#include <bits/stdc++.h>
using namespace std;
string s;
map<string,bool> used;
int ans;
int main(){
    cin>>s;
    for (int i=1;i<=s.size();++i){
        if (used[s]==false) ++ans;
        used[s]=true;
        s=s[s.size()-1]+s;
        s.erase(s.end()-1);
    }
    cout<<ans;
}