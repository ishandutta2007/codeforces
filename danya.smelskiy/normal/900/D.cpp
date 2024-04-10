#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


struct matrix {
    long long a[3][3];
};
long long x,y;
vector<long long > v;
inline long long pwx(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
map<int,bool> used;
map<int,int> res;
inline long long solve(long long y){
    if (y==1) return 1;
    if (y==2) return 1;
    if (y==3) return 3;
    if (used[y]) return res[y];
    long long ans=pwx(2ll,y-1ll);
    int k;
    for (int i=0;i<v.size() && v[i]*v[i]<=y;++i) if (y%v[i]==0){
        k=v[i];
        if (k>1) {
            ans-=solve(y/k);
            if (ans<0) ans+=md;
        }
        k=y/v[i];
        if (k!=v[i] && k>1) {
            ans-=solve(v[i]);
            if (ans<0) ans+=md;
        }
    }
    used[y]=true;
    return res[y]=ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    if (x>y || ((y%x)!=0)) {
        cout<<0;
        return 0;
    }
    if (x==y) {
        cout<<1;
        return 0;
    }
    y/=x;
    for (int i=1;i*i<=y;++i)
    if (y%i==0) {
        v.push_back(i);
        if ((y/i)!=i) v.push_back(y/i);
    }
    sort(v.begin(),v.end());
    cout<<solve(y);
}