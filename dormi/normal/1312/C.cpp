#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<lli> bits;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        bits.clear();
        int n;
        lli k;
        cin >> n >> k;
        lli a;
        bool work=true;
        for (int i = 0; i < n; i++) {
            cin >> a;
            int ind = 0;
            while (a) {
                lli cur = a % k;
                if (cur >1) {
                    work=false;
                }
                if(cur) {
                    if (bits.count(ind))work = false;
                    bits.insert(ind);
                }
                ind++;
                a/=k;
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}