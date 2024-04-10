#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000;

int n;
int v[N+5],val[N+5];

struct info {
    int i;
    int l;
    int val;
};

bool operator<(info a,info b) {
    if(a.val==b.val)
        return a.i<b.i;
    return a.val<b.val;
}

set<info>s;

int x=0;

int sol[N+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        val[i]=i-v[i];
        s.insert({i,v[i],val[i]});
    }
    for(int i=1;i<=n;i++) {
        int mi=x+s.begin()->val;
        if(i-1==mi)
            x++;
        sol[i]=x;
        s.erase({i,v[i],val[i]});
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=sol[i]-v[i];
    cout<<ans<<"\n";
    return 0;
}
/**

**/