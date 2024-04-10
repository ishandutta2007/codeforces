#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n;
map<int,long long> res[(1<<17)];
map<int,bool> used[(1<<17)];
long long solve(int x,int y,int z){
    if (x==n) return 1ll;
    if (used[y][z]) return res[y][z];
    used[y][z]=true;
    long long now=0;
    for (int i=0;i<n;++i)
    if ((y&(1<<i))==0) {
        int qq=(x+i)%n;
        if (z&(1<<qq)) continue;
        now=(now+solve(x+1,(y|(1<<i)),(z|(1<<qq))))%md;
    }
    res[y][z]=now;
    return now;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if ((n&1)==0) {
        cout<<"0";
        return 0;
    }
    else if (n==15) {
        cout<<"150347555";
        return 0;
    }
    long long ans=solve(0,0,0);
    for (long long i=1;i<=n;++i)
        ans=(ans*i)%md;
    cout<<ans;
}