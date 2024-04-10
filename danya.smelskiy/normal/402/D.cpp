#include <bits/stdc++.h>
using namespace std;



int n,m,x,a[5005];
map<int,bool> used;
map<int,bool> b;
map<int,int> f;

int solve(int x){
    int xx=x;
    int res=0;
    if (used[x]) return f[x];
    used[x]=true;
    for (int i=2;i<=sqrt(x);++i) {
        while (x%i==0) {
            if (b[i]==true) --res;
            else ++res;
            x/=i;
        }
    }
    if (x>1) {
        if (b[x]==true) --res;
        else ++res;
    }
    f[xx]=res;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i){
        cin>>x;
        b[x]=true;
    }
    while (true) {
        int pos=0;
        int last=0;
        int best=0;
        for (int i=1;i<=n;++i){
            last=__gcd(last,a[i]);
            int res=solve(last);
            if (res<0) {
                pos=i;
                best=last;
            }
        }
        if (pos==0) break;
        for (int i=1;i<=pos;++i)
            a[i]/=best;
    }
    int ans=0;
    for (int i=1;i<=n;++i)
        ans+=solve(a[i]);
    cout<<ans;
}