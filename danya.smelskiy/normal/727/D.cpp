#include <bits/stdc++.h>
using namespace std;

int kol[7];
string s;
int n;
bool used[100005];
int ans[100005];
int ff[100005];
int sss[100005];


inline int get(string x){
    if (x=="S") return 1;
    else if (x=="M") return 2;
    else if (x=="L") return 3;
    else if (x=="XL") return 4;
    else if (x=="XXL") return 5;
    else return 6;
}
inline void no(){
    cout<<"NO";
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=6;++i)
        cin>>kol[i];
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s;
        string f="";
        string ss="";
        bool t=false;
        for (int j=1;j<=s.size();++j)
            if (s[j-1]==',') {
                t=true;
            } else {
                if (t==false) f+=s[j-1];
                else ss+=s[j-1];
            }
        if (t==false) {
            int q=get(f);
            used[i]=true;
            ans[i]=q;
            if (kol[q]==0) no();
            --kol[q];
            continue;
        }
        ff[i]=get(f);
        sss[i]=get(ss);
        if (ff[i]>sss[i]) swap(ff[i],sss[i]);
    }
    for (int i=1;i<=6;++i) {
        for (int j=1;j<=n;++j)  if (kol[i] && used[j]==false && (ff[j]==i-1 && sss[j]==i)){
            used[j]=true;
            --kol[i];
            ans[j]=i;
        }
        for (int j=1;j<=n;++j)  if (kol[i] && used[j]==false && (ff[j]==i && sss[j]==i+1)){
            used[j]=true;
            --kol[i];
            ans[j]=i;
        }
    }
    for (int i=1;i<=n;++i)
        if (used[i]==false) no();
    cout<<"YES"<<'\n';
    for (int i=1;i<=n;++i)
        if (ans[i]==1) cout<<"S"<<'\n';
    else if (ans[i]==2) cout<<"M"<<'\n';
    else if (ans[i]==3) cout<<"L"<<'\n';
    else if (ans[i]==4) cout<<"XL"<<'\n';
    else if (ans[i]==5) cout<<"XXL"<<'\n';
    else if (ans[i]==6) cout<<"XXXL"<<'\n';
}