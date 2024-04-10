#include <bits/stdc++.h>
using namespace std;



long long n;
pair<int,long long> res;

void get(long long x,int y,long long z){
    if (x==0) {
        if (y>res.first || (y==res.first && z>res.second)) res=make_pair(y,z);
        return;
    }
    long long l=1;
    long long r=min(x,(long long)1e6);
    while (l<r-1) {
        long long mid=(l+r)>>1;
        if (mid*mid*mid<=x) l=mid;
        else r=mid;
    }
    if (r*r*r<=x) l=r;
    get(x-l*l*l,y+1,z+l*l*l);
    if (l-1) get(l*l*l-1-(l-1)*(l-1)*(l-1),y+1,z+(l-1)*(l-1)*(l-1));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    get(n,0,0);
    cout<<res.first<<" "<<res.second;
}