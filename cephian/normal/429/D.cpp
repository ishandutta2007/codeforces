#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll INF = 0x7fffffffffffffff;
const int N = 100005;
ll a[N],p[N],n;

bool cmp(const int& i,const int& j) {
    return a[i] < a[j];
}

ll dst(ll a, ll b, ll c, ll d) {
    return (a-c)*(a-c)+(b-d)*(b-d);
}

ll closest(int i, int j) {
    if(i == j) return INF;
    ll d = min(closest(i,(i+j)/2),closest((i+j)/2+1,j));
    ll mid = (i+j)/2;
    int sz = 0;
    for(int k = i; k <= j; ++k)
        if((mid-k)*(mid-k) < d)
            p[sz++]=k;
    sort(p,p+sz,cmp);
    for(int k = 0; k < sz; ++k) {
        for(int l = k+1; l < sz; ++l) {
            ll q = dst(p[k],a[p[k]],p[l],a[p[l]]);
            if(q >= d) break;
            d = q;
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i  = 0; i < n; ++i) {
        cin >> a[i];
        if(i) a[i] += a[i-1];
        p[i]=i;
    }
    cout << closest(0,n-1) << "\n";

}