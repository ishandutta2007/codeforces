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

char s[1000001],a[1000001],b[1000001];
char must[26],used[26],tmust[26],tused[26];
int can(char a,char b) {
    if ((must[a-'a'] != 0) && (must[a-'a'] != b)) return 0;
    else if ((used[b-'a'] != 0) && (used[b-'a'] != a)) return 0;
    return 1;
}
int main() {
    int i,j;
    int t,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %s %s %s",&k,s,a,b);

        int n = strlen(s),no = 0;
        for (i = 0; i < k; i++) must[i] = used[i] = 0;
        for (i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                if (can(s[i],a[i])) must[s[i]-'a'] = a[i],used[a[i]-'a'] = s[i];
                else {
                    no = 1;
                    break;
                }
            }
            else break;
        }
        if (no) {
            printf("NO\n");
            continue;
        }
        if (i == n) {
            vector<char> un;
            for (i = 0; i < k; i++) {
                if (used[i] == 0) un.pb(i+'a');
            }
            printf("YES\n");
            for (i = 0; i < k; i++) {
                if (must[i] == 0) must[i] = un.back(),un.pop_back();
                printf("%c",must[i]);
            }
            printf("\n");
            continue;
        }
        int p = i,yes = 0;
        for (i = a[p]-'a'+1; i < b[p]-'a'; i++) {
            if (can(s[p],i+'a')) {
                must[s[p]-'a'] = i+'a',used[i] = s[p];
                yes = 1;
                break;
            }
        }
        if (yes) {
            vector<char> un;
            for (i = 0; i < k; i++) {
                if (used[i] == 0) un.pb(i+'a');
            }
            printf("YES\n");
            for (i = 0; i < k; i++) {
                if (must[i] == 0) must[i] = un.back(),un.pop_back();
                printf("%c",must[i]);
            }
            printf("\n");
            continue;
        }
        for (i = 0; i < k; i++) tmust[i] = must[i],tused[i] = used[i];
        if (can(s[p],a[p])) {
            int f = 0;
            must[s[p]-'a'] = a[p],used[a[p]-'a'] = s[p];
            for (i = p+1; i < n; i++) {
                for (j = k-1; j >= (f ? 0:(a[i]-'a')); j--) {
                    if (can(s[i],j+'a')) break;
                }
                if (j < (f ? 0:(a[i]-'a'))) {
                    no = 1;
                    break;
                }
                else {
                    must[s[i]-'a'] = j+'a',used[j] = s[i];
                    if (j > a[i]-'a') f = 1;
                }
            }
            if (!no) {
                vector<char> un;
                for (i = 0; i < k; i++) {
                    if (used[i] == 0) un.pb(i+'a');
                }
                printf("YES\n");
                for (i = 0; i < k; i++) {
                    if (must[i] == 0) must[i] = un.back(),un.pop_back();
                    printf("%c",must[i]);
                }
                printf("\n");
                continue;
            }
        }
        for (i = 0; i < k; i++) must[i] = tmust[i],used[i] = tused[i];
        if (can(s[p],b[p])) {
            int f = 0;
            no = 0;
            must[s[p]-'a'] = b[p],used[b[p]-'a'] = s[p];
            for (i = p+1; i < n; i++) {
                for (j = 0; j <= (f ? k-1:(b[i]-'a')); j++) {
                    if (can(s[i],j+'a')) break;
                }
                if (j > (f ? k-1:(b[i]-'a'))) {
                    no = 1;
                    break;
                }
                else {
                    must[s[i]-'a'] = j+'a',used[j] = s[i];
                    if (j < b[i]-'a') f = 1;
                }
            }
            if (!no) {
                vector<char> un;
                for (i = 0; i < k; i++) {
                    if (used[i] == 0) un.pb(i+'a');
                }
                printf("YES\n");
                for (i = 0; i < k; i++) {
                    if (must[i] == 0) must[i] = un.back(),un.pop_back();
                    printf("%c",must[i]);
                }
                printf("\n");
                continue;
            }
        }
        printf("NO\n");
    }

    return 0;
}