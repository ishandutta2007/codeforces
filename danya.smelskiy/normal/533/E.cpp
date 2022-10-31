#include <bits/stdc++.h>
using namespace std;

bool used[100][100];
string s,ss;
int ans;

int n;
inline void check(string a,string b){
    int l=0;
    while (l<n && a[l]==b[l]) ++l;
    string k1="",k2="";
    for (int i=l;i<a.size();++i) {
        k1+=a[i];
        k2+=b[i];
    }
    a=k1;
    b=k2;
    int r=a.size()-1;
    while (r+1 && a[r]==b[r]) --r;
    k1="",k2="";
    for (int i=0;i<=r;++i){
        k1+=a[i];
        k2+=b[i];
    }
    a=k1; b=k2;
    int x=a[0]-'a';
    int y=b[(int)b.size()-1]-'a';
    l=1;
    r=0;
    while (l<a.size() && a[l]==b[r]) {
        ++l;
        ++r;
    }
    if (l!=a.size()) return;
    if (used[x][y]==false) {
        used[x][y]=true;
        ++ans;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s>>ss;
    check(s,ss);
    check(ss,s);

    cout<<ans;
}