#include <bits/stdc++.h>
using namespace std;

string s;
long long n,ans=1e9;
vector<int> v;
int main(){
    cin>>s>>n;
    if (s.size()<n+1){
        cout<<s.size()-1;
        return 0;
    }
    for (int i=0;i<s.size();++i){
        if (s[i]=='0') v.push_back(i);
    }
    if (v.size()<n) {
        cout<<s.size()-1;
        return 0;
    }
    for (int i=0;i<=v.size()-1-n+1;++i){
        ans=min(ans,v[i+n-1]-v[i]-(n-1)+s.size()-1-v[i+n-1]);
    }
    cout<<ans;
}