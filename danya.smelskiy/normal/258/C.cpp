#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

long long a[100005];
int kol[100006];
long long ans;
int n;

long long p(long long x,long long y){
    if (x==0) return 0;
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ++kol[a[i]];
    }
    for (int i=1;i<=1e5+5;++i)
        kol[i]+=kol[i-1];
    for (int i=1;i<=1e5;++i) {
        vector<int> q;
        int x=i;
        for (int j=1;j*j<=x;++j)
        if (x%j==0) {
            q.push_back(j);
            if (j*j!=x) q.push_back(x/j);
        }
        sort(q.begin(),q.end());
        q.push_back(1e5+5);
        long long res=1;
        int y;
        for (int j=0;j<q.size()-1;++j){
            x=q[j];
            y=q[j+1]-1;
            int xx=x;
            x=(kol[y]-kol[x-1]);
            if (xx<=i && y>i) {
                long long res2=res;
                res=(res*p(j+1,x))%md;
                res2=(res2*p(j,x))%md;
                res-=res2;
                if (res<md) res+=md;
            } else res=(res*p(j+1,x))%md;
        }
        ans=(ans+res)%md;
    }
    cout<<ans;
}