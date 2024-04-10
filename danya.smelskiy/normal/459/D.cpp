#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int b[1000005];
map<int,int> cnt;
long long ans;
int f[1000005];


long long get(int x) {
    long long res=0;
    for (int i=x;i>=0;i=(i&(i+1))-1) {
        res+=f[i];
    }
    return res;
}

inline void update(int x,int y) {
    for (int i=x;i<=n;i=(i|(i+1))) {
        f[i]+=y;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        int x=a[i];
        ++cnt[x];
        b[i]=cnt[x];
    }
    cnt.clear();
    for (int i=n;i>0;--i) {
        ans+=get(b[i]-1);
        int x=a[i];
        ++cnt[x];
        update(cnt[x],1);
    }
    cout<<ans;
}