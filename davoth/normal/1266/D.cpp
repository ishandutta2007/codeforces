#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;

int n,m;
ll A[N],B[N],p=1;
vector<pair<pair<ll,ll>,ll> > t;
int main(){
    fast_io;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int x,y;
        ll z;
        cin >> x >> y >> z;
        A[x]+=z;
        B[y]+=z;
    }
    for (int i = 1; i <= n; i++) {
        ll k = min(A[i], B[i]);
        A[i] -= k;
        B[i] -= k;
    }
    for(int i=0; i<n; i++) continue;
    for(int i=1; i<=n; i++){
        while(A[i]!=0){
            if(B[p]!=0) t.push_back({{i,p},min(A[i],B[p])});
            ll MM=min(A[i],B[p]);
            A[i]-=MM;
            B[(B[p]==MM ? p++ : p)]-=MM;
        }
    }
    cout << t.size() << '\n';
    for(auto i : t) cout << i.F.F << ' ' << i.F.S << ' ' << i.S << '\n';
    return 0;
}