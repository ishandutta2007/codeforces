#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct info {
    ll x;
    int t;
};

const int N=1234567;

info q[N];
int p=1,u=1;
ll a,b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    q[1]={a,0};
    while(p<=u) {
        ll x=q[p].x;
        p++;
        if(2*x<=b) {
            q[++u]={2*x,p-1};
        }
        if(10*x+1<=b) {
            q[++u]={10*x+1,p-1};
        }
    }
    for(int i=1;i<=u;i++) {
        if(q[i].x==b) {
            cout<<"YES\n";
            int id=i;
            vector<int>print;
            while(id) {
                print.push_back(q[id].x);
                id=q[id].t;
            }
            reverse(print.begin(),print.end());
            cout<<print.size()<<"\n";
            for(auto itr:print) {
                cout<<itr<<" ";
            }
            cout<<"\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}

/**

**/