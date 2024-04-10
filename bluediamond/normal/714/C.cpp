#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int gt(ll x) {
    int ans=0;
    int bt=1;
    while(x) {
        if(x%2) {
            ans+=bt;
        }
        bt*=2;
        x/=10;
    }
    return ans;
}

int gts(string a) {
    int ans=0;
    int bt=1;
    for(int i=a.size()-1;i>=0;i--) {
        if(a[i]=='1') {
            ans+=bt;
        }
        bt*=2;
    }
    return ans;
}

const int N=(1<<20);

int cnt[N];

string a;
ll x;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while(q--) {
        string t;
        cin>>t;
        if(t=="+") {
            cin>>x;
            cnt[gt(x)]++;
        }
        if(t=="-") {
            cin>>x;
            cnt[gt(x)]--;
        }
        if(t=="?") {
            cin>>a;
            cout<<cnt[gts(a)]<<"\n";
        }
    }
    return 0;
}
/**


**/