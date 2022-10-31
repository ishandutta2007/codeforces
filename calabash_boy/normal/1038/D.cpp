

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> pll;
#define rep(i,l,r) for (int i=l;i<r;i++)
int n;
vi a;
const int inf = 0x3f3f3f3f;
int main(){
    cin>>n;
    if (n == 1){
        int x;
        cin>>x;
        cout<<x<<endl;
        return 0;
    }
    a.resize(n);
    ll t = 0;
    int maxx = -inf;
    int minn = inf;
    for (int i=0;i<n;i++){
        cin>>a[i];
        t += abs(a[i]);
        maxx = max(maxx,a[i]);
        minn = min(minn,a[i]);
    }


    if (maxx < 0) {
        t += 2ll * maxx;
    }
    if (minn > 0) {
        t -= 2ll * minn;
    }
    cout << t << endl;
    return 0;

}