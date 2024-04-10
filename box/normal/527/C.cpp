// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h,w,n;cin>>h>>w>>n;
    set<int>X,Y;
    multiset<int>CX,CY;
    auto ins=[&](int b,set<int>&f,multiset<int>&e){
        auto g=f.insert(b).first;
        e.erase(e.find(*next(g)-*prev(g)));
        e.insert(*next(g)-*g);
        e.insert(*g-*prev(g));
    };
    X.insert(0);X.insert(h);CX.insert(h);
    Y.insert(0);Y.insert(w);CY.insert(w);
    while(n--){
        char a;int b;
        cin>>a>>b;
        if(a!='H')ins(b,X,CX);
        else ins(b,Y,CY);
        cout<<1ll**CX.rbegin()**CY.rbegin()<<endl;
    }
}