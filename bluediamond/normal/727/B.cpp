#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=1000+5;
char s[N];
ll n;
ll p;

inline void skip() {
    while(!isdigit(s[p]) && p<n) {
        p++;
    }
}

inline ll get(string x) {
    ll ans=0;
    for(auto itr:x) {
        if(itr=='.') {
            continue;
        }
        ans=10*ans+itr-'0';
    }
    return ans;
}

inline ld number() {
    string x;
    while(isdigit(s[p]) || s[p]=='.') {
        x+=s[p];
        p++;
    }
    if(x.size()<=2) {
        return get(x);
    }
    ld ans=0;
    if(x[x.size()-3]=='.') {
        ans+=(ld)(x.back()-'0')*0.01;x.pop_back();
        ans+=(ld)(x.back()-'0')*0.1;x.pop_back();
        x.pop_back();
    }
    ans+=get(x);
    return ans;
}

ld ans=0;

vector<ll>cif;
vector<bool>is;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin.getline(s,N);
    n=strlen(s);
    while(p<n) {
        skip();
        ans+=number();
    }
    ll x=ans;
    if(x==0) {
        cif.push_back(0);
        is.push_back(0);
    }
    ans-=(ld)x;
    while(x) {
        cif.push_back(x%10);
        if(cif.size()%3==1 && cif.size()>1) {
            is.push_back(1);
        }
        else {
            is.push_back(0);
        }
        x/=10;
    }
    for(ll i=cif.size()-1;i>=0;i--) {
        cout<<cif[i];
        if(is[i]) {
            cout<<".";
        }
    }
    if(ans>0.00000000001) {
        ans*=100;
        cout<<".";
        long long x=ans+0.001;
        cout<<x/10;
        cout<<x%10;
    }
    cout<<"\n";
    return 0;
}

/**

**/