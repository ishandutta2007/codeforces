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

deque<int> S,T;
vpii ans;
int main() {
    string s,t;
    cin >> s >> t;

    int i;
    for (i = 0; i < s.size(); i++) {
        if (S.empty() || ((i > 0) && (s[i] != s[i-1]))) S.pb(0);
        S.back()++;
    }
    for (i = 0; i < t.size(); i++) {
        if (T.empty() || ((i > 0) && (t[i] != t[i-1]))) T.pb(0);
        T.back()++;
    }
    int c = (s[0] != t[0]);
    while (1) {
        if ((S.size() == 1) && (T.size() == 1)) break;
        if (!c) {
            int f = 0;
            if (S.size() > T.size()) {
                if ((S.size() >= 3) && (T.size() >= 2)) {
                    ans.pb(mp(S[0]+S[1],T[0]));
                    int x = S.front();
                    S.pop_front();
                    int y = S.front();
                    S.pop_front();
                    S.front() += T.front();
                    T.pop_front();
                    T.front() += y;
                    T.push_front(x);
                    f = 1;
                }
            }
            else {
                if ((T.size() >= 3) && (S.size() >= 2)) {
                    ans.pb(mp(S[0],T[0]+T[1]));
                    int x = T.front();
                    T.pop_front();
                    int y = T.front();
                    T.pop_front();
                    T.front() += S.front();
                    S.pop_front();
                    S.front() += y;
                    S.push_front(x);
                    f = 1;
                }
            }
            if (!f) {
                if ((S.size() == 2) && (T.size() == 2)) {
                    ans.pb(mp(S[0],T[0]+T[1]));
                    ans.pb(mp(T[0],0));
                    break;
                }
                else {
                    if (S.size() == 1) {
                        if (T.size() == 2) {
                            ans.pb(mp(0,T[0]));
                            break;
                        }
                        else {
                            if ((T.size() % 4) == 3) {
                                int x = S.front(),y = 0;
                                S.pop_front();
                                for (i = 0; i < T.size()/2+1; i++) S.pb(T[i]),y += T[i];
                                int ss = T.size();
                                for (i = 0; i < ss/2+1; i++) T.pop_front();
                                ans.pb(mp(x,y));
                                T.front() += x;
                            }
                            else if ((T.size() % 4) == 0) {
                                int x = S.front(),y = 0;
                                S.pop_front();
                                for (i = 0; i < T.size()/2; i++) S.pb(T[i]),y += T[i];
                                int ss = T.size();
                                for (i = 0; i < ss/2; i++) T.pop_front();
                                ans.pb(mp(x,y));
                                T.front() += x;
                            }
                            else if ((T.size() % 4) == 1) {
                                int x = S.front(),y = 0;
                                S.pop_front();
                                for (i = 0; i < T.size()/2; i++) S.pb(T[i]),y += T[i];
                                int ss = T.size();
                                for (i = 0; i < ss/2; i++) T.pop_front();
                                ans.pb(mp(x,y));
                                T.front() += x;
                            }
                            else {
                                int x = S.front(),y = 0;
                                S.pop_front();
                                for (i = 0; i < T.size()/2; i++) S.pb(T[i]),y += T[i];
                                S.back() += x;
                                int ss = T.size();
                                for (i = 0; i < ss/2; i++) T.pop_front();
                                ans.pb(mp(0,y));
                                c = 1;
                            }
                        }
                    }
                    else if (T.size() == 1) {
                        if (S.size() == 2) {
                            ans.pb(mp(S[0],0));
                            break;
                        }
                        else {
                            if ((S.size() % 4) == 3) {
                                int x = T.front(),y = 0;
                                T.pop_front();
                                for (i = 0; i < S.size()/2+1; i++) T.pb(S[i]),y += S[i];
                                int ss = S.size();
                                for (i = 0; i < ss/2+1; i++) S.pop_front();
                                ans.pb(mp(y,x));
                                S.front() += x;
                            }
                            else if ((S.size() % 4) == 0) {
                                int x = T.front(),y = 0;
                                T.pop_front();
                                for (i = 0; i < S.size()/2; i++) T.pb(S[i]),y += S[i];
                                int ss = S.size();
                                for (i = 0; i < ss/2; i++) S.pop_front();
                                ans.pb(mp(y,x));
                                S.front() += x;
                            }
                            else if ((S.size() % 4) == 1) {
                                int x = T.front(),y = 0;
                                T.pop_front();
                                for (i = 0; i < S.size()/2; i++) T.pb(S[i]),y += S[i];
                                int ss = S.size();
                                for (i = 0; i < ss/2; i++) S.pop_front();
                                ans.pb(mp(y,x));
                                S.front() += x;
                            }
                            else {
                                int x = T.front(),y = 0;
                                T.pop_front();
                                for (i = 0; i < S.size()/2; i++) T.pb(S[i]),y += S[i];
                                T.back() += x;
                                int ss = S.size();
                                for (i = 0; i < ss/2; i++) S.pop_front();
                                ans.pb(mp(y,0));
                                c = 1;
                            }
                        }
                    }
                }
            }
        }
        else {
            int f = 0;
            if ((S.size() >= 2) && (T.size() >= 2)) {
                if (S.size() == 2) {
                    if ((T.size() >= 5) && ((T.size() % 4) == 1)) {
                        int x = S.front(),y = 0;
                        S.pop_front();
                        int xx = S.front();
                        S.pop_front();
                        for (i = 0; i < T.size()/2+1; i++) S.pb(T[i]),y += T[i];
                        S.back() += xx;
                        int ss = T.size();
                        for (i = 0; i < ss/2+1; i++) T.pop_front();
                        ans.pb(mp(x,y));
                        T.front() += x;
                        f = 1;
                    }
                    else if ((T.size() >= 5) && ((T.size() % 4) == 2)) {
                        int x = S.front(),y = 0;
                        S.pop_front();
                        int xx = S.front();
                        S.pop_front();
                        for (i = 0; i < T.size()/2; i++) S.pb(T[i]),y += T[i];
                        S.back() += xx;
                        int ss = T.size();
                        for (i = 0; i < ss/2; i++) T.pop_front();
                        ans.pb(mp(x,y));
                        T.front() += x;
                        f = 1;
                    }
                }
                else if (T.size() == 2) {
                    if ((S.size() >= 5) && ((S.size() % 4) == 1)) {
                        int x = T.front(),y = 0;
                        T.pop_front();
                        int xx = T.front();
                        T.pop_front();
                        for (i = 0; i < S.size()/2+1; i++) T.pb(S[i]),y += S[i];
                        T.back() += xx;
                        int ss = S.size();
                        for (i = 0; i < ss/2+1; i++) S.pop_front();
                        ans.pb(mp(y,x));
                        S.front() += x;
                        f = 1;
                    }
                    else if ((S.size() >= 5) && ((S.size() % 4) == 2)) {
                        int x = T.front(),y = 0;
                        T.pop_front();
                        int xx = T.front();
                        T.pop_front();
                        for (i = 0; i < S.size()/2; i++) T.pb(S[i]),y += S[i];
                        T.back() += xx;
                        int ss = S.size();
                        for (i = 0; i < ss/2; i++) S.pop_front();
                        ans.pb(mp(y,x));
                        S.front() += x;
                        f = 1;
                    }
                }
                if (!f) {
                    ans.pb(mp(S[0],T[0]));
                    int x = S.front();
                    S.pop_front();
                    int y = T.front();
                    T.pop_front();
                    S.front() += y;
                    T.front() += x;
                    f = 1;
                }
            }
            if (!f) {
                if (S.size() == 1) {
                    if (T.size() == 2) {
                        ans.pb(mp(S[0],T[0]));
                        break;
                    }
                    else {
                        if ((T.size() % 4) == 3) {
                            int x = S.front(),y = 0;
                            S.pop_front();
                            for (i = 0; i < T.size()/2+1; i++) S.pb(T[i]),y += T[i];
                            int ss = T.size();
                            for (i = 0; i < ss/2+1; i++) T.pop_front();
                            ans.pb(mp(x,y));
                            T.push_front(x);
                        }
                        else if ((T.size() % 4) == 0) {
                            int x = S.front(),y = 0;
                            S.pop_front();
                            for (i = 0; i < T.size()/2; i++) S.pb(T[i]),y += T[i];
                            int ss = T.size();
                            for (i = 0; i < ss/2; i++) T.pop_front();
                            ans.pb(mp(x,y));
                            T.push_front(x);
                        }
                        else if ((T.size() % 4) == 1) {
                            int x = S.front(),y = 0;
                            S.pop_front();
                            for (i = 0; i < T.size()/2+1; i++) S.pb(T[i]),y += T[i];
                            int ss = T.size();
                            for (i = 0; i < ss/2+1; i++) T.pop_front();
                            ans.pb(mp(x,y));
                            T.front() += x;
                        }
                        else {
                            int x = S.front(),y = 0;
                            S.pop_front();
                            for (i = 0; i < T.size()/2; i++) S.pb(T[i]),y += T[i];
                            int ss = T.size();
                            for (i = 0; i < ss/2; i++) T.pop_front();
                            ans.pb(mp(x,y));
                            T.front() += x;
                        }
                    }
                }
                else if (T.size() == 1) {
                    if (S.size() == 2) {
                        ans.pb(mp(S[0],T[0]));
                        break;
                    }
                    else {
                        if ((S.size() % 4) == 3) {
                            int x = T.front(),y = 0;
                            T.pop_front();
                            for (i = 0; i < S.size()/2+1; i++) T.pb(S[i]),y += S[i];
                            int ss = S.size();
                            for (i = 0; i < ss/2+1; i++) S.pop_front();
                            ans.pb(mp(y,x));
                            S.push_front(x);
                        }
                        else if ((S.size() % 4) == 0) {
                            int x = T.front(),y = 0;
                            T.pop_front();
                            for (i = 0; i < S.size()/2; i++) T.pb(S[i]),y += S[i];
                            int ss = S.size();
                            for (i = 0; i < ss/2; i++) S.pop_front();
                            ans.pb(mp(y,x));
                            S.push_front(x);
                        }
                        else if ((S.size() % 4) == 1) {
                            int x = T.front(),y = 0;
                            T.pop_front();
                            for (i = 0; i < S.size()/2+1; i++) T.pb(S[i]),y += S[i];
                            int ss = S.size();
                            for (i = 0; i < ss/2+1; i++) S.pop_front();
                            ans.pb(mp(y,x));
                            S.front() += x;
                        }
                        else {
                            int x = T.front(),y = 0;
                            T.pop_front();
                            for (i = 0; i < S.size()/2; i++) T.pb(S[i]),y += S[i];
                            int ss = S.size();
                            for (i = 0; i < ss/2; i++) S.pop_front();
                            ans.pb(mp(y,x));
                            S.front() += x;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",(int) ans.size());
    for (i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i].first,ans[i].second);

    return 0;
}