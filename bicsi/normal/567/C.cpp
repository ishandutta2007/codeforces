#include <bits/stdc++.h>

using namespace std;
typedef int var;
typedef pair<var, var> Pair;

unordered_map<var, vector<var> > Ap1, Ap2;
var V[500000];

#define DIM 100000
char buff[DIM];
var poz = DIM - 1;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE


    var n, k;
    cin>>n>>k;

    for(int i=1; i<=n; i++) {
        cin>>V[i];
        Ap1[V[i]].push_back(i);
    }

    for(int i=n; i; i--) {
        Ap2[V[i]].push_back(i);
    }

    long long total = 0;

    for(int ii=1; ii<=n; ii++) {
        int no = V[ii];

        if(no % k != 0) continue;
        if(fabs(1LL * no * k) > 1e9) continue;

        vector<int> &V1 = Ap1[no / k];
        vector<int> &V2 = Ap2[no * k];

        int i, p1=-1, p2=-1;
        for(i=1; i<V1.size(); i<<=1);
        for(;i;i>>=1) {
            if(p1+i<V1.size() && V1[p1+i] < ii)
                p1+=i;
        }
        for(i=1; i<V2.size(); i<<=1);
        for(;i;i>>=1) {
            if(p2+i<V2.size() && V2[p2+i] > ii)
                p2+=i;
        }

        total += 1LL*(p1+1)*(p2+1);

    }

    cout<<total;

    return 0;
}