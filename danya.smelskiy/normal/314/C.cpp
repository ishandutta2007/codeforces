#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n;
long long x,f[1000005];
long long ans;
long long get(int x){
    long long res=0;
    while (x>0) {
        res=(res+f[x]+md)%md;
        x=(x&(x+1))-1;
    }
    return res;
}
inline void update(int x,long long y){
    while (x<=1e6) {
        f[x]=(f[x]+y)%md;
        x=(x|(x+1));
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        long long res=get(x);
        res=((res*x)%md+x)%md;
        long long q=(get(x)-get(x-1)+md)%md;
        update(x,-q);
        update(x,res);
    }

    cout<<get(1e6);
}