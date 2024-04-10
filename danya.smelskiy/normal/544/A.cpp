#include <bits/stdc++.h>
using namespace std;
long long n,sz;
string s;
string a[100001];
bool used[10000];
int main(){
    cin>>n>>s;
    sz=1;
    a[sz]=s[0];
    used[s[0]]=true;
    for (int i=1;i<s.size();++i){
        string last=a[sz];
        if (used[s[i]]==false && sz<n){
            ++sz;
            used[s[i]]=true;
            a[sz]=s[i];
        } else {
            a[sz]=a[sz]+s[i];
        }
    }
    if (sz<n) cout<<"NO";
    else {
        cout<<"YES"<<'\n';
        for (int i=1;i<=sz;++i)
            cout<<a[i]<<'\n';
    }
}