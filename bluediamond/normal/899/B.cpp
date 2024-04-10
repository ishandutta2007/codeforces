#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int d[]={0,31,0,31,30,31,30,31,31,30,31,30,31};

bool leap(int x) {
    if(x%4==0) {
        if(x%100==0) {
            if(x%400==0) {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int a,l;

int cnt() {
    if(l==2) {
        if(leap(a)) {
            return 29;
        }
        return 28;
    }
    return d[l];
}

void nxt() {
    l++;
    if(l>12) {
        a++;
        l=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    a=l=1;
    vector<int>ans;
    while(a<=1000) {
        ans.push_back(cnt());
        nxt();
    }
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    for(int i=0;i+n-1<ans.size();i++) {
        bool ok=1;
        for(int j=0;j<n;j++) {
            if(ans[i+j]!=v[j]) {
                ok=0;
                break;
            }
        }
        if(ok) {
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}
/**

**/