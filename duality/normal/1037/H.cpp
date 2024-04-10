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

int IS(int *arr,int *s,int n,int a,char *sl,int *lms,int n2) {
    int i;
    int *num = new int[a],*num2 = new int[a+1];
    for (i = 0; i < a; i++) num[i] = num2[i] = 0;
    for (i = 0; i < n; i++) num[s[i]]++,num2[s[i]+1]++;
    for (i = 1; i < a; i++) num[i] += num[i-1],num2[i] += num2[i-1];
    memset(arr,-1,n*sizeof(int));
    for (i = n2-1; i >= 0; i--) arr[--num[s[lms[i]]]] = lms[i];
    for (i = 0; i < n; i++) {
        if ((arr[i] > 0) && !sl[arr[i]-1]) arr[num2[s[arr[i]-1]]++] = arr[i]-1;
    }
    for (i = 0; i < n2; i++) num[s[lms[i]]]++;
    for (i = n-1; i >= 0; i--) {
        if ((arr[i] > 0) && sl[arr[i]-1]) arr[--num[s[arr[i]-1]]] = arr[i]-1;
    }
    delete[] num;
    delete[] num2;
    return 0;
}
int *SAIS(int *s,int n,int a) {
    int i,n2 = 0,c = 0;
    int *arr = new int[n],*lms = new int[n];
    char *sl = new char[n];
    sl[n-1] = 1;
    for (i = n-2; i >= 0; i--) {
        sl[i] = (s[i] < s[i+1]) || ((s[i] == s[i+1]) && sl[i+1]);
        if (!sl[i] && sl[i+1]) lms[n2++] = i+1;
    }
    reverse(lms,lms+n2),IS(arr,s,n,a,sl,lms,n2);
    int *lms2 = new int[n2];
    n2 = 0;
    for (i = 0; i < n; i++) {
        if ((arr[i] > 0) && sl[arr[i]] && !sl[arr[i]-1]) lms2[n2++] = arr[i];
    }
    arr[n-1] = c;
    for (i = 1; i < n2; i++) {
        int x = lms2[i-1],y = lms2[i];
        if (s[x] < s[y]) c++;
        else {
            while (1) {
                x++,y++;
                if (s[x] < s[y]) {
                    c++;
                    break;
                }
                else if ((sl[x] && !sl[x-1]) || (sl[y] && !sl[y-1])) break;
            }
        }
        arr[lms2[i]] = c;
    }
    if (c+1 < n2) {
        int *s2 = new int[n2];
        for (i = 0; i < n2; i++) s2[i] = arr[lms[i]];
        int *arr2 = SAIS(s2,n2,c+1);
        for (i = 0; i < n2; i++) lms2[i] = lms[arr2[i]];
        delete[] s2;
        delete[] arr2;
    }
    IS(arr,s,n,a,sl,lms2,n2);
    delete[] lms;
    delete[] sl;
    delete[] lms2;
    return arr;
}
vector<int> suffixArray(const string &s) {
    int i,n = s.size(),*s2 = new int[n+1];
    for (i = 0; i < n; i++) s2[i] = s[i];
    s2[n] = 0,s2 = SAIS(s2,n+1,256);
    return vector<int>(s2+1,s2+n+1);
}

int l[200000],r[200000],pos[200000],len[200000];
int arr[500000],lcp[500000],inv[500000];
int sparse[500000][19],logg[500001];
int qlcp(int x,int y) {
    x = inv[x],y = inv[y];
    if (x > y) swap(x,y);
    y--;
    int l = logg[y-x+1];
    return min(sparse[x][l],sparse[y-(1 << l)+1][l]);
}
pii queries[200000];
string ans[200000];
int tree[1 << 18];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = 1e9;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int update(int s,int e,int ai,int i,int num) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        tree[i] = num;
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,ai,2*i+1,num),update(mid+1,e,ai,2*i+2,num);
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int query(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 1e9;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return min(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);

    int i,q;
    string s,x;
    cin >> s >> q;
    int n = s.size();
    for (i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> x;
        l[i]--,r[i]--,pos[i] = s.size()+1,len[i] = x.size();
        s += "$" + x;
    }

    vi v = suffixArray(s);
    for (i = 0; i < v.size(); i++) arr[i] = v[i],inv[arr[i]] = i;
    int j,p = 0;
    for (i = 0; i < s.size(); i++) {
        if (inv[i] == s.size()-1) p = 0;
        else {
            j = arr[inv[i]+1];
            while ((i+p < s.size()) && (j+p < s.size()) && (s[i+p] == s[j+p])) p++;
        }
        lcp[inv[i]] = p;
        if (p > 0) p--;
    }
    for (i = 0; i < s.size()-1; i++) sparse[i][0] = lcp[i];
    for (i = 1; (1 << i) < s.size(); i++) {
        for (j = 0; j < s.size()-(1 << i); j++) sparse[j][i] = min(sparse[j][i-1],sparse[j+(1 << (i-1))][i-1]);
    }
    for (i = 2; i < s.size(); i++) logg[i] = logg[i/2]+1;
    for (i = 0; i < q; i++) queries[i] = mp(inv[pos[i]],i);
    p = s.size()-1;
    sort(queries,queries+q,greater<pii>());
    build(0,n-1,0);
    for (i = 0; i < q; i++) {
        while ((p >= 0) && (p > queries[i].first)) {
            if (arr[p] < n) update(0,n-1,arr[p],0,p);
            p--;
        }
        int u = queries[i].second,a = 1e9;
        for (j = r[u]; j >= max(l[u],r[u]-len[u]-2); j--) {
            int w = min(qlcp(j,pos[u]),min(len[u],r[u]-j+1));
            if (j+w <= r[u]) {
                if (s[pos[u]+w] < s[j+w]) a = min(a,inv[j]);
            }
        }
        if (l[u] <= j) a = min(a,query(0,n-1,l[u],j,0));
        if (a < 1e9) ans[u] = s.substr(arr[a],qlcp(arr[a],pos[u])+1);
    }
    for (i = 0; i < q; i++) cout << (ans[i].empty() ? "-1":ans[i]) << endl;

    return 0;
}