#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool pot(string a,string b) {
    int l=b.size();
    int cur=0;
    for(auto itr:a) {
        if(itr==b[cur]) {
            cur++;
            if(cur==l) {
                return 1;
            }
        }
    }
    return 0;
}

string a;
string b;

int sza;
int szb;

vector<int>v;

bool ok(int len) {
    vector<bool>viz(sza);
    for(int i=0;i<sza;i++) {
        viz[i]=0;
    }
    for(int i=0;i<len;i++) {
        viz[v[i]-1]=1;
    }
    string ans="";
    for(int i=0;i<sza;i++) {
        if(viz[i]==0) {
            ans+=a[i];
        }
    }
    return pot(ans,b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    sza=a.size();
    szb=b.size();
    for(int i=1;i<=sza;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int r=0,pas=(1<<30);
    while(pas) {
        if(r+pas<=sza && ok(r+pas)==1) {
            r+=pas;
        }
        pas/=2;
    }
    cout<<r<<"\n";
    return 0;
}