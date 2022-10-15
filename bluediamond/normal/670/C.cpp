#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000+5;
int n,v[N];

int m;

map<int,int>mp;

struct info {
    int id;
    pair<int,int>a;
};

info ans[N];

bool cmp(info x,info y) {
    return x.a>y.a;
}

int a[N],b[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        mp[v[i]]++;
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++) {
        cin>>b[i];
        ans[i]={i,make_pair(mp[a[i]],mp[b[i]])};
    }
    sort(ans+1,ans+m+1,cmp);
    cout<<ans[1].id<<"\n";
    return 0;
}
/**

**/