#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> v;
vector<string> vv;
int kol;
string q[100];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        int res=0;
        for (int j=0;j<s.size();++j)
            if (s[j]!='0') res+=(1<<(s.size()-j-1));
        if (res==0) ++kol;
        else v.push_back(res);
        if (res) vv.push_back(s);
    }
    int ans=kol;
    if (v.size()) {
        ans=kol+1;
        q[1]=vv[0];
    }
    for (int i=0;i<v.size();++i)
        for (int j=i+1;j<v.size();++j)
    if ((v[i]&v[j])==0) {
        ans=kol+2;
        q[1]=vv[i];
        q[2]=vv[j];
    }
    for (int i=0;i<v.size();++i)
    for (int j=0;j<v.size();++j)
    for (int k=0;k<v.size();++k)
    if ((v[i]&v[j])==0 && (v[i]&v[k])==0 && (v[j]&v[k])==0) {
        ans=kol+3;
        q[1]=vv[i];
        q[2]=vv[j];
        q[3]=vv[k];
    }
    cout<<ans<<'\n';
    for (int i=1;i<=ans-kol;++i)
        cout<<q[i]<<" ";
    while (kol--) cout<<"0 ";
}