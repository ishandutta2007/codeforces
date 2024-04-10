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

int modPow(int b,int e) {
    int r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*b) % MOD;
        e >>= 1;
        b = ((LLI) b*b) % MOD;
    }
    return r;
}
char cc[101];
int power[5][1000];
int pre[105][5],suff[105][5],pre2[105][5],suff2[105][5];
int num[100001][26];
string ss[100001];
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);

    int i,j;
    int n,q;
    string s0,t;
    cin >> n >> q >> s0 >> t;
    for (i = 0; i < s0.size(); i++) {
        for (j = 0; j < 5; j++) {
            pre[i][j] = (i == 0) ? 0:pre[i-1][j];
            pre[i][j] = ((LLI) (31+j)*pre[i][j]+s0[i]) % MOD;
        }
    }
    for (i = 0; i < 5; i++) {
        power[i][0] = 1;
        for (j = 1; j < 1000; j++) power[i][j] = ((LLI) (31+i)*power[i][j-1]) % MOD;
    }
    for (i = s0.size()-1; i >= 0; i--) {
        for (j = 0; j < 5; j++) {
            suff[i][j] = (i == s0.size()-1) ? 0:suff[i+1][j];
            suff[i][j] = (suff[i][j]+(LLI) power[j][s0.size()-i-1]*s0[i]) % MOD;
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j < 26; j++) num[i][j] = (2*num[i-1][j]) % MOD;
        num[i][t[i-1]-'a'] = (num[i][t[i-1]-'a']+1) % MOD;
    }

    //ss[0] = s0;
    //for (i = 1; i <= n; i++) ss[i] = ss[i-1] + t[i-1] + ss[i-1];

    int k,l;
    string w;
    for (i = 0; i < q; i++) {
        cin >> k >> w;

        LLI ans = 0;
        if (w.size() <= s0.size()) {
            for (j = 0; j < w.size(); j++) {
                for (l = 0; l < 5; l++) {
                    pre2[j][l] = (j == 0) ? 0:pre2[j-1][l];
                    pre2[j][l] = ((LLI) (31+l)*pre2[j][l]+w[j]) % MOD;
                }
            }
            for (j = w.size()-1; j >= 0; j--) {
                for (l = 0; l < 5; l++) {
                    suff2[j][l] = (j == w.size()-1) ? 0:suff2[j+1][l];
                    suff2[j][l] = (suff2[j][l]+(LLI) power[l][w.size()-j-1]*w[j]) % MOD;
                }
            }
            for (j = 0; j < w.size(); j++) {
                int a = 1,b = 1;
                for (l = 0; l < 5; l++) {
                    if ((j > 0) && (pre2[j-1][l] != suff[s0.size()-j][l])) a = 0;
                    if ((j < w.size()-1) && (suff2[j+1][l] != pre[w.size()-j-2][l])) b = 0;
                }
                if (a && b) ans += num[k][w[j]-'a'],ans %= MOD;
            }
            for (j = 0; j <= s0.size()-w.size(); j++) {
                for (l = 0; l < 5; l++) {
                    LLI x = pre[j+w.size()-1][l]-(LLI) power[l][w.size()]*((j == 0) ? 0:pre[j-1][l]);
                    x %= MOD;
                    if (x < 0) x += MOD;
                    if (x != pre2[w.size()-1][l]) break;
                }
                if (l == 5) ans += modPow(2,k),ans %= MOD;
            }
        }
        else {
            memset(cc,'?',sizeof(cc));
            vector<pair<string,int> > vv,vv2;
            for (j = 0; j < w.size(); j++) {
                if (cc[j % (s0.size()+1)] == '?') cc[j % (s0.size()+1)] = w[j];
                else if (cc[j % (s0.size()+1)] != w[j]) cc[j % (s0.size()+1)] = '/';
            }
            for (j = 0; j < s0.size()+1; j++) {
                for (l = 0; l < 5; l++) {
                    pre2[j][l] = (j == 0) ? 0:pre2[j-1][l];
                    pre2[j][l] = ((LLI) (31+l)*pre2[j][l]+cc[j]) % MOD;
                }
            }
            for (j = s0.size(); j >= 0; j--) {
                for (l = 0; l < 5; l++) {
                    suff2[j][l] = (j == s0.size()) ? 0:suff2[j+1][l];
                    suff2[j][l] = (suff2[j][l]+(LLI) power[l][s0.size()-j]*cc[j]) % MOD;
                }
            }
            for (j = 0; j <= s0.size(); j++) {
                int a = 1,b = 1;
                for (l = 0; l < 5; l++) {
                    if ((j > 0) && (pre2[j-1][l] != suff[s0.size()-j][l])) a = 0;
                    if ((j < s0.size()) && (suff2[j+1][l] != pre[s0.size()-j-1][l])) b = 0;
                }
                if (a && b) {
                    string w2;
                    for (l = j; l < w.size(); l += s0.size()+1) w2 += w[l];
                    vv.pb(mp(w2,1));
                }
            }
            for (j = 0; j < k; j++) {
                if (vv.empty()) break;
                for (l = 0; l < vv.size(); l++) {
                    if (vv[l].first.size() == 1) {
                        LLI a = num[k][vv[l].first[0]-'a'];
                        a -= (LLI) modPow(2,k-j)*num[j][vv[l].first[0]-'a'];
                        a %= MOD;
                        ans += a*vv[l].second,ans %= MOD;
                        continue;
                    }
                    int m;
                    int bad[2];
                    bad[0] = bad[1] = 0;
                    for (m = 0; m < vv[l].first.size(); m++) {
                        if (vv[l].first[m] != t[j]) bad[m & 1] = 1;
                    }
                    if (!bad[1]) {
                        string q;
                        for (m = 0; m < vv[l].first.size(); m += 2) q += vv[l].first[m];
                        vv2.pb(mp(q,vv[l].second));
                    }
                    if (!bad[0]) {
                        string q;
                        for (m = 1; m < vv[l].first.size(); m += 2) q += vv[l].first[m];
                        vv2.pb(mp(q,vv[l].second));
                    }
                }
                sort(vv2.begin(),vv2.end()),vv.clear();
                for (l = 0; l < vv2.size(); l++) {
                    if (!vv.empty() && (vv.back().first == vv2[l].first)) {
                        vv.back().second += vv2[l].second;
                        if (vv.back().second >= MOD) vv.back().second -= MOD;
                    }
                    else vv.pb(vv2[l]);
                }
                vv2.clear();
            }
            if (ans < 0) ans += MOD;
        }
        cout << ans << endl;
        /*cout << ss[k] << endl;
        int aa = 0;
        for (j = 0; j <= ss[k].size()-w.size(); j++) {
            if (ss[k].substr(j,w.size()) == w) aa++;
        }
        cout<<"aa:"<<aa<<endl;
        string z;
        for (j = 0; j < ss[k].size(); j++) {
            if ((j % (s0.size()+1)) == s0.size()) cout << ss[k][j],z += ss[k][j];
        }
        string y = "aaaaabaaabaaabaaaaaaabaaaba";
        aa = 0;
        for (j = 0; j <= z.size()-y.size(); j++) {
            if (z.substr(j,y.size()) == y) aa++;
        }
        cout<<endl;
        cout<<aa<<endl;*/
    }

    return 0;
}