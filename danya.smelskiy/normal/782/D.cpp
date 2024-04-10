#include <bits/stdc++.h>
using namespace std;

string s,ss;
int n;
string name1[1005];
string name2[1005];
map<string,bool> used1,used2;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s>>ss;
        string sk=""; sk+=s[0]; sk+=s[1];
        string ssk=""; ssk+=sk; sk+=s[2]; ssk+=ss[0];
        name1[i]=sk;
        name2[i]=ssk;
    }
    bool t=false;
    for (int i=1;i<=n;++i){
        if (used1[name1[i]]==true) {
            t=true;
            break;
        }
        used1[name1[i]]=true;
    }
    if (!t) {
        cout<<"YES"<<'\n';
        for (int i=1;i<=n;++i)
            cout<<name1[i]<<'\n';
        return 0;
    }
    t=false;
    for (int i=1;i<=n;++i){
        if (used2[name2[i]]==true) {
            t=true;
            break;
        }
        used2[name2[i]]=true;
    }
    if (!t) {
        cout<<"YES"<<'\n';
        for (int i=1;i<=n;++i)
            cout<<name2[i]<<'\n';
        return 0;
    }
    cout<<"NO";
}