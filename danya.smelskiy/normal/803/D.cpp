#include <bits/stdc++.h>
using namespace std;


int n;
string s;
vector<string> v;
string last;
inline bool chek(int mid){
    int kol=1;
    int laststr=0;
    for (int i=0;i<v.size();++i) {
        if (v[i].size()>mid) return false;
        if (laststr+v[i].size()<=mid) laststr+=v[i].size();
        else {
            ++kol;
            laststr=v[i].size();
        }
    }
    return kol<=n;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    getline(cin,s);
    getline(cin,s);
    s+=" ";
    for (int i=1;i<=s.size();++i){
        if (s[i-1]==' ' || s[i-1]=='-') {
            if (i!=s.size()) last+=" ";
            v.push_back(last);
            last="";
        } else last+=s[i-1];
    }
    int l=1;
    int r=1e9;
    while (l<r-1) {
        int mid=(l+r)/2;
        if (chek(mid)) r=mid;
        else l=mid;
    }
    if (chek(l)) cout<<l;
    else cout<<r;
}