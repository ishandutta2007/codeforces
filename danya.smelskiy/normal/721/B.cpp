#include <bits/stdc++.h>
using namespace std;
string s;
bool t;
string a[100001],s1,s2;
int n,k;
int good,bad;
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    cin>>s1;
    for (int i=1;i<=n;++i){
        s2=a[i];
        if (s2.size()<s1.size()) ++good;
        if (s2.size()==s1.size() && s2!=s1) ++bad;
    }
    bad+=good;
    cout<<(good/k*5)+good+1<<" "<<(bad/k*5)+bad+1;
    }