#include <bits/stdc++.h>
using namespace std;

int n;
string s[200001];
map<string,bool> used;
int main(){
    cin>>n;
    for (int i=n;i>0;--i)
        cin>>s[i];
    for (int i=1;i<=n;++i)
    if (used[s[i]]==false) {
        cout<<s[i]<<'\n';
        used[s[i]]=true;
    }
}