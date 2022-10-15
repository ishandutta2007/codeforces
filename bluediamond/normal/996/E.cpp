#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct info {
    ll x,y;
    int i;
};

ll f(ll x,ll y) {
    return x*x+y*y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll lim=1500000;
    lim*=lim;
    int n;
    cin>>n;
    vector<info>v(n);
    vector<int>ans(n);
    for(int i=0;i<n;i++) {
        cin>>v[i].x>>v[i].y;
        v[i].i=i;
    }
    while(1) {
        random_shuffle(v.begin(),v.end());
        ll x=0;
        ll y=0;
        for(auto itr:v) {
            ll c1=f(x+itr.x,y+itr.y);
            ll c2=f(x-itr.x,y-itr.y);
            if(c1<c2) {
                ans[itr.i]=1;
                x+=itr.x;
                y+=itr.y;
            }
            else {
                ans[itr.i]=-1;
                x-=itr.x;
                y-=itr.y;
            }
        }
        if(f(x,y)<=lim) {
            for(auto itr:ans)
                cout<<itr<<" ";
            cout<<"\n";
            return 0;
        }
    }
    return 0;
}
/**

**/