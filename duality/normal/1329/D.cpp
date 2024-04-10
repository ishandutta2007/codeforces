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

template<typename T1,typename T2>
ostream& operator<<(ostream& output,const pair<T1,T2> &p) {
    output << "(" << p.first << "," << p.second << ")";
    return output;
}
template<typename T>
ostream& operator<<(ostream& output,const vector<T> &v) {
    unsigned int i;
    bool f = 1;
    for (i = 0; i < v.size(); i++) {
        if (!f) output << " ";
        output << v[i];
        f = 0;
    }

    return output;
}
template<typename T>
ostream& operator<<(ostream& output,const list<T> &l) {
    typename list<T>::const_iterator it;
    bool f = 1;
    for (it = l.begin(); it != l.end(); it++) {
        if (!f) output << " ";
        output << *it;
        f = 0;
    }

    return output;
}
template<typename T1,typename T2>
ostream& operator<<(ostream& output,const map<T1,T2> &m) {
    typename map<T1,T2>::const_iterator it;
    bool f = 1;
    for (it = m.begin(); it != m.end(); it++) {
        if (!f) output << " ";
        output << "(" << it->first << " -> " << it->second << ")";
        f = 0;
    }

    return output;
}
template<typename T>
ostream& operator<<(ostream& output,const set<T> &s) {
    typename set<T>::const_iterator it;
    bool f = 1;
    for (it = s.begin(); it != s.end(); it++) {
        if (!f) output << " ";
        output << *it;
        f = 0;
    }

    return output;
}


char s[200001];
int l[200000],r[200000];
vpii ans;
set<pair<int,char> > S;
int occ[26];
vi Q[26],Q2[26];
int getAns(int s,int e) {
    if (s > e) return 0;
    int i = s;
    if (r[s] == s) {
        getAns(s+1,e);
        ans.pb(mp(s,s));
        return 0;
    }
    vi v;
    while ((r[i] != -1) && (r[i] > i)) v.pb(i),i = r[i];
    v.pb(i);
    for (i = 1; i < v.size(); i++) getAns(v[i-1]+1,v[i]-1);
    getAns(v.back()+1,e);
    ans.pb(mp(v[0],v.back()));
    return 0;
}
int bit[200001];
set<int> sad;
int main() {
    int i;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%s",s);
        int n = strlen(s);

        for (i = 0; i < n; i++) r[i] = (i == n-1) ? -1:i+1,l[i] = (i == 0) ? -1:i-1;
        fill(occ,occ+26,0);
        for (i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) S.insert(mp(i,s[i])),occ[s[i]-'a']++;
        }
        debug S;
        for (auto it = S.begin(); it != S.end(); it++) {
            auto it2 = it;
            it2++;
            if ((it2 != S.end()) && (it->second != it2->second)) {
                Q[it->second-'a'].pb(it->first);
                Q2[it2->second-'a'].pb(it2->first);
            }
        }
        while (1) {
            int mi = -1;
            for (i = 0; i < 26; i++) {
                if (occ[i] == 0) continue;
                if ((mi == -1) || (occ[i] > occ[mi])) mi = i;
            }
            if (mi == -1) break;
            printVar(mi);
            debug S;
            while (!Q[mi].empty()) {
                debug "here";
                auto it = S.lower_bound(mp(Q[mi].back(),'\0'));
                if ((it == S.end()) || (it == --S.end()) || (*it != mp(Q[mi].back(),s[Q[mi].back()]))) Q[mi].pop_back();
                else {
                    auto it2 = it;
                    it2++;
                    if (it->second == it2->second) Q[mi].pop_back();
                    else break;
                }
            }
            while (!Q2[mi].empty()) {
                auto it = S.lower_bound(mp(Q2[mi].back(),'\0'));
                if ((it == S.end()) || (it == S.begin()) || (*it != mp(Q2[mi].back(),s[Q2[mi].back()]))) Q2[mi].pop_back();
                else {
                    auto it2 = it;
                    it2--;
                    if (it->second == it2->second) Q2[mi].pop_back();
                    else break;
                }
            }
            if (!Q[mi].empty()) {
                int u = Q[mi].back();
                printVar(u);
                Q[mi].pop_back();
                auto it = S.lower_bound(mp(u,'\0'));
                auto it2 = it;
                it2++;
                int a = it->first,b = it2->first,c = r[b];
                printVar(a);
                printVar(b);
                printVar(c);
                l[r[a]] = r[b] = -1;
                l[c] = a,r[a] = c;
                assert(it->second != it2->second);
                occ[it->second-'a']--,occ[it2->second-'a']--;
                S.erase(it),it2 = S.erase(it2);
                it = it2;
                if ((it != S.begin()) && (it2 != S.end())) {
                    it--;
                    if (it->second != it2->second) {
                        Q[it->second-'a'].pb(it->first);
                        Q2[it2->second-'a'].pb(it2->first);
                    }
                }
            }
            else if (!Q2[mi].empty()) {
                int u = Q2[mi].back();
                printVar(u);
                Q2[mi].pop_back();
                auto it = S.lower_bound(mp(u,'\0'));
                auto it2 = it;
                it--;
                int a = it->first,b = it2->first,c = r[b];
                l[r[a]] = r[b] = -1;
                l[c] = a,r[a] = c;
                assert(it->second != it2->second);
                occ[it->second-'a']--,occ[it2->second-'a']--;
                S.erase(it),it2 = S.erase(it2);
                it = it2;
                if ((it != S.begin()) && (it2 != S.end())) {
                    it--;
                    if (it->second != it2->second) {
                        Q[it->second-'a'].pb(it->first);
                        Q2[it2->second-'a'].pb(it2->first);
                    }
                }
            }
            else break;
        }
        int c = 0;
        char z;
        for (i = 0; i < 26; i++) {
            if (occ[i] > 0) c++,z = i+'a';
        }
        assert(c <= 1);
        for (auto it = S.begin(); it != S.end(); it++) {
            int u = it->first,v = r[it->first];
            assert(it->second == z);
            r[u] = l[v] = -1;
        }
        printArr(l,n);
        printArr(r,n);
        getAns(0,n-1);
        printf("%d\n",ans.size());
        int j;
        fill(bit,bit+n+1,0);
        for (i = 0; i < n; i++) {
            for (j = i+1; j <= n; j += j & (-j)) bit[j]++;
        }
        for (i = 0; i < n; i++) sad.insert(i);
        for (i = 0; i < ans.size(); i++) {
            int s = 0,e = 0;
            for (j = ans[i].first+1; j > 0; j -= j & (-j)) s += bit[j];
            for (j = ans[i].second+1; j > 0; j -= j & (-j)) e += bit[j];
            // :( :( :(
            auto soclose = sad.lower_bound(ans[i].first);
            while ((soclose != sad.end()) && (*soclose <= ans[i].second)) {
                int iamsodumb = *soclose;
                for (j = iamsodumb+1; j <= n; j += j & (-j)) bit[j]--;
                soclose = sad.erase(soclose);
            }
            printf("%d %d\n",s,e);
        }


        for (i = 0; i < 26; i++) {
            Q[i].clear();
            Q2[i].clear();
        }
        S.clear();
        ans.clear();
    }

    return 0;
}