#include <bits/stdc++.h>
using namespace std;
constexpr long long GAP=20'000'000'000'000'005ll;
pair<long long,long long> locations[100];
long long dist(const pair<long long,long long>& a, const pair<long long,long long>& b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
    ios_base::sync_with_stdio(false);
    long long x0,y0,ax,ay,bx,by,xs,ys,t;
    cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
    int n=0;
    while(x0<=GAP&&y0<=GAP){
        locations[n++]={x0,y0};
        x0=ax*x0+bx;
        y0=ay*y0+by;
    }
    int best=0;
    for(int i=0;i<n;++i){
        long long d=dist({xs,ys},locations[i]);
        if(d<=t){
            best=max(best,1);
            for(int j=i-1;j>=0;--j){
                long long d2=dist(locations[i],locations[j]);
                if(d+d2<=t)best=max(best,i-j+1);
            }
            for(int j=i+1;j<n;++j){
                long long d2=dist(locations[i],locations[j]);
                if(d+d2<=t)best=max(best,j-i+1);
            }
        }
    }
    cout<<best<<'\n';
}