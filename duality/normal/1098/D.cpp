#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

char c[500000];
int x[500000];
vi sorted;
LLI bit[500001];
set<pii> S,S2;
int main() {
    int i;
    int q;
    scanf("%d",&q);
    for (i = 0; i < q; i++) scanf(" %c %d",&c[i],&x[i]),sorted.pb(x[i]);
    sort(sorted.begin(),sorted.end());
    sorted.resize(unique(sorted.begin(),sorted.end())-sorted.begin());

    int j;
    for (i = 0; i < q; i++) {
        if (c[i] == '+') {
            S.insert(mp(x[i],i));
            auto it = S.find(mp(x[i],i));
            if ((it != S.begin()) && (it != (--S.end()))) {
                auto it2 = it,it3 = it;
                it2++,it3--;
                if (it2->first > 2*it3->first) S2.erase(*it2);
            }
            if (it != (--S.end())) {
                it++;
                if (it->first > 2*x[i]) S2.insert(*it);
                it--;
            }
            if (it != S.begin()) {
                it--;
                if (x[i] > 2*it->first) S2.insert(mp(x[i],i));
                it++;
            }
            int p = lower_bound(sorted.begin(),sorted.end(),x[i])-sorted.begin();
            for (j = p+1; j <= sorted.size(); j += j & (-j)) bit[j] += x[i];
        }
        else {
            auto it = S.lower_bound(mp(x[i],0));
            if (it != (--S.end())) {
                it++;
                if (it->first > 2*x[i]) S2.erase(*it);
                it--;
            }
            if (it != S.begin()) {
                it--;
                auto it2 = it;
                it2++;
                if (x[i] > 2*it->first) S2.erase(*it2);
                it++;
            }
            if ((it != S.begin()) && (it != (--S.end()))) {
                auto it2 = it,it3 = it;
                it2++,it3--;
                if (it2->first > 2*it3->first) S2.insert(*it2);
            }
            S.erase(it);
            int p = lower_bound(sorted.begin(),sorted.end(),x[i])-sorted.begin();
            for (j = p+1; j <= sorted.size(); j += j & (-j)) bit[j] -= x[i];
        }
        /*for (auto it = S.begin(); it != S.end(); it++) {
            cout << it->first<<","<<it->second<<" ";
        }cout<<endl;
        for (auto it = S2.begin(); it != S2.end(); it++) {
            cout << it->first<<","<<it->second<<" ";
        }cout<<endl;*/
        if (S.empty()) printf("0\n");
        else {
            int ans = S.size()-1;
            for (auto it = S2.begin(); it != S2.end(); it++) {
                int x = it->first;
                LLI s = 0;
                int p = lower_bound(sorted.begin(),sorted.end(),x)-sorted.begin()-1;
                for (j = p+1; j > 0; j -= j & (-j)) s += bit[j];
                if (2*s < x) ans--;
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}