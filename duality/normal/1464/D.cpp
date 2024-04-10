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
#define MOD 1000000007

int p[1000000],v[1000000];
vi cc,cc2;
map<vi,int> M;
queue<vi> Q;
int prod(vi v) {
    int i,p = 1;
    for (i = 0; i < v.size(); i++) p *= v[i];
    return p;
}
int getAns(vi v,int m) {
    int i,j;
    sort(v.begin(),v.end());
    M.clear();
    M[v] = 0;
    while (!Q.empty()) Q.pop();
    Q.push(v);
    while (!Q.empty()) {
        vi u = Q.front();
        Q.pop();

        if (prod(u) == m) return M[u];
        for (i = 0; i < u.size(); i++) {
            for (j = i+1; j < u.size(); j++) {
                vi v = u;
                v[i] += v[j],swap(v[j],v.back()),v.pop_back();
                sort(v.begin(),v.end());
                if (!M.count(v)) M[v] = M[u]+1,Q.push(v);
            }
        }
        for (i = 0; i < u.size(); i++) {
            if (u[i] >= 2) {
                for (j = 1; j < u[i]; j++) {
                    vi v = u;
                    v[i] = j,v.pb(u[i]-j);
                    sort(v.begin(),v.end());
                    if (!M.count(v)) M[v] = M[u]+1,Q.push(v);
                }
            }
        }
    }
    return -1;
}
set<vi> S;
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&p[i]),p[i]--;

        int ans = 0;
        LLI ans2 = 1;
        fill(v,v+n,0);
        for (i = 0; i < n; i++) {
            if (!v[i]) {
                int u = i,c = 0;
                do {
                    v[u] = 1,u = p[u],c++;
                } while (u != i);
                cc.pb(c);
            }
        }
        sort(cc.begin(),cc.end());
        /*if (S.count(cc)) {
            cc.clear();
            next_permutation(p,p+n);
            continue;
        }
        else S.insert(cc);*/
        if ((n % 3) == 0) {
            for (i = 0; i < n/3; i++) ans2 = (3*ans2) % MOD;
        }
        else if ((n % 3) == 1) {
            ans2 = 4;
            for (i = 0; i < (n-4)/3; i++) ans2 = (3*ans2) % MOD;
        }
        else if ((n % 3) == 2) {
            ans2 = 2;
            for (i = 0; i < (n-2)/3; i++) ans2 = (3*ans2) % MOD;
        }
        for (i = 0; i < cc.size(); i++) {
            if ((cc[i] % 3) == 0) ans += cc[i]/3-1;
            else cc2.pb(cc[i]);
        }
        if ((n % 3) == 0) {
            int one = 0,two = 0;
            for (i = 0; i < cc2.size(); i++) {
                if ((cc2[i] % 3) == 1) ans += (cc2[i]-1)/3,one++;
                else ans += (cc2[i]-2)/3,two++;
            }
            ans += min(one,two);
            int m = min(one,two);
            one -= m,two -= m;
            if (one > two) ans += 2*(one/3);
            else if (two > one) ans += 3*(two/3);
        }
        else if ((n % 3) == 1) {
            for (i = 0; i < cc2.size(); i++) {
                if ((cc2[i] % 3) == 1) {
                    if (cc2[i] >= 4) break;
                }
            }
            if (i < cc2.size()) {
                int one = 0,two = 0;
                for (i = 0; i < cc2.size(); i++) {
                    if ((cc2[i] % 3) == 1) ans += (cc2[i]-1)/3,one++;
                    else ans += (cc2[i]-2)/3,two++;
                }
                int oo = one,tt = two;

                int temp = ans;
                if (two >= 2) two -= 2;
                ans += min(one,two);
                int m = min(one,two);
                one -= m,two -= m;
                if (one > two) ans += 2*(one/3);
                else if (two > one) ans += 3*(two/3);
                int aa1 = ans;
                ans = temp,one = oo,two = tt;
                one--,ans--;
                ans += min(one,two);
                m = min(one,two);
                one -= m,two -= m;
                if (one > two) ans += 2*(one/3);
                else if (two > one) ans += 3*(two/3);
                ans = min(ans,aa1);
            }
            else {
                int one = 0,two = 0;
                for (i = 0; i < cc2.size(); i++) {
                    if ((cc2[i] % 3) == 1) ans += (cc2[i]-1)/3,one++;
                    else ans += (cc2[i]-2)/3,two++;
                }
                if ((one == 1) && (two == 0)) ans++;
                ans += min(one,two);
                int m = min(one,two);
                one -= m,two -= m;
                //cout<<"one:"<<one<<"two:"<<two<<endl;
                //cout<<"ans:"<<ans<<endl;
                if (one > two) ans += 2*((one-1)/3);
                else if (two > one) ans += 3*((two-2)/3);
            }
        }
        else {
            int one = 0,two = 0;
            for (i = 0; i < cc2.size(); i++) {
                if ((cc2[i] % 3) == 1) ans += (cc2[i]-1)/3,one++;
                else ans += (cc2[i]-2)/3,two++;
            }
            if (two == 0) one -= 2,ans++;
            else two--;
            ans += min(one,two);
            int m = min(one,two);
            one -= m,two -= m;
            if (one > two) ans += 2*(one/3);
            else if (two > one) ans += 3*(two/3);
        }

        printf("%I64d %d\n",ans2,ans);
        //printArr(cc,cc.size());
        //int aa = getAns(cc,ans2);
        //cout<<ans<<","<<aa<<endl;
        //assert(ans == aa);
        cc.clear(),cc2.clear();
        //next_permutation(p,p+n);
    }

    return 0;
}