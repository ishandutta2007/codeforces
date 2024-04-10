#include <bits/stdc++.h>
using namespace std;



int n;
string s;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=1;i<=n;++i) {
        int x=s[i-1]-'0';
        if (x==0) v.push_back(11);
        else v.push_back(x);
    }
    bool t=false;
    for (int i=0;i<v.size();++i) {
        int x=v[i];
        x-=3;
        if (x<1) t=true;
    }
    if (t==false) {
        cout<<"NO";
        return 0;
    }
    t=false;
    for (int i=0;i<v.size();++i) {
        int x=v[i];
        x+=3;
        if (x>11 || x==10) t=true;
    }
    if (t==false) {
        cout<<"NO";
        return 0;
    }
    t=false;
    for (int i=0;i<v.size();++i) {
        int x=v[i];
        if (x==1 || x==4 || x==7 || x==11) t=true;
    }
    if (t==false) {
        cout<<"NO";
        return 0;
    }
    t=false;
    for (int i=0;i<v.size();++i) {
        int x=v[i];
        if (x==3 || x==6 || x==9 || x==11) t=true;
    }
    if (t==false) cout<<"NO";
    else cout<<"YES";
}