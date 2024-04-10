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
vector<int> suffixArray(char *s,int n) {
    int i,*s2 = new int[n+1];
    for (i = 0; i < n; i++) s2[i] = s[i];
    s2[n] = 0,s2 = SAIS(s2,n+1,256);
    return vector<int>(s2+1,s2+n+1);
}

int n;
char s[200000];
struct query { int l,r,i; };
bool comp(query a,query b) {
    return a.l > b.l;
}
query queries[200000];
int ans[200000];
vi arr;
int inv[200000],lcp[200000],sparse[200000][18],logg[200001];
int getLcp(int x,int y) {
    x = inv[x],y = inv[y];
    if (x > y) swap(x,y);
    y--;
    int l = logg[y-x+1];
    return min(sparse[x][l],sparse[y-(1 << l)+1][l]);
}
vi f[200001];
int pre[26][200001],repL[200000],repR[200000],rep2[200000];
int treeL[1 << 19],treeR[1 << 19];
int build(int s,int e,int i) {
    if (s == e) {
        treeL[i] = treeR[i] = 1e9;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    treeL[i] = treeR[i] = 1e9;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int t,int num) {
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        if (t == 1) treeL[i] = min(treeL[i],num);
        else if (t == 2) treeR[i] = min(treeR[i],num);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,t,num),update(mid+1,e,as,ae,2*i+2,t,num);
    return 0;
}
int process(int s,int e,int i) {
    if (s == e) {
        repL[s] = treeL[i],repR[s] = treeR[i];
        return 0;
    }

    int mid = (s+e) / 2;
    treeL[2*i+1] = min(treeL[2*i+1],treeL[i]);
    treeR[2*i+1] = min(treeR[2*i+1],treeR[i]);
    treeL[2*i+2] = min(treeL[2*i+2],treeL[i]);
    treeR[2*i+2] = min(treeR[2*i+2],treeR[i]);
    process(s,mid,2*i+1),process(mid+1,e,2*i+2);
    return 0;
}
vi getZ(string s) {
    int i,l = 0,r = 0;
    vi Z(s.size(),0);
    for (i = 1; i < s.size(); i++) {
        if (i > r) {
            l = r = i;
            while ((r < s.size()) && (s[r-l] == s[r])) r++;
            Z[i] = (r--)-l;
        }
        else {
            if (Z[i-l] < r-i+1) Z[i] = Z[i-l];
            else {
                l = i;
                while ((r < s.size()) && (s[r-l] == s[r])) r++;
                Z[i] = (r--)-l;
            }
        }
    }
    return Z;
}
int findReps(int l,int r) {
    if (l == r) return 0;
    int i,mid = (l+r) / 2;
    string a = string(s+l,s+mid+1),b = string(s+mid+1,s+r+1);
    string ra = a,rb = b;
    reverse(ra.begin(),ra.end()),reverse(rb.begin(),rb.end());
    vi zl1 = getZ(ra),zl2 = getZ(b+a),zr1 = getZ(b),zr2 = getZ(ra+rb);
    for (i = l; i <= mid; i++) {
        int x = (i == l) ? 0:zl1[mid-i+1],y = zl2[b.size()+i-l];
        int L = mid-i+1;
        int ll = max(i-x,i-L+1),rr = min(i+y-L,i);
        ll = max(ll,l),rr = min(rr,r-2*L+1);
        if (ll <= rr) update(0,n-1,ll,rr,0,2,2*L),update(0,n-1,ll+2*L-1,rr+2*L-1,0,1,2*L);
    }
    for (i = mid+1; i <= r; i++) {
        int x = (i == r) ? 0:zr1[i-mid],y = zr2[ra.size()+r-i];
        int L = i-mid;
        int ll = max(i-L-y+1,mid-L+1),rr = min(x-L+mid+1,mid);
        ll = max(ll,l),rr = min(rr,r-2*L+1);
        if (ll <= rr) update(0,n-1,ll,rr,0,2,2*L),update(0,n-1,ll+2*L-1,rr+2*L-1,0,1,2*L);
    }
    findReps(l,mid),findReps(mid+1,r);
    return 0;
}
int tree2[1 << 19];
int build2(int s,int e,int i) {
    if (s == e) {
        tree2[i] = 1e9;
        return 0;
    }

    int mid = (s+e) / 2;
    build2(s,mid,2*i+1),build2(mid+1,e,2*i+2);
    tree2[i] = 1e9;
    return 0;
}
int update2(int s,int e,int ai,int i,int num) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        tree2[i] = num;
        return 0;
    }

    int mid = (s+e) / 2;
    update2(s,mid,ai,2*i+1,num),update2(mid+1,e,ai,2*i+2,num);
    tree2[i] = min(tree2[2*i+1],tree2[2*i+2]);
    return 0;
}
int query2(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 1e9;
    else if ((s >= qs) && (e <= qe)) return tree2[i];

    int mid = (s+e) / 2;
    return min(query2(s,mid,qs,qe,2*i+1),query2(mid+1,e,qs,qe,2*i+2));
}
int main() {
    int i;
    int q,l,r;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&l,&r);
        queries[i] = (query){l-1,r-1,i};
    }
    sort(queries,queries+q,comp);

    int j;
    arr = suffixArray(s,n);
    int p = 0;
    for (i = 0; i < n; i++) inv[arr[i]] = i;
    for (i = 0; i < n; i++) {
        if (inv[i] == (n-1)) p = 0;
        else {
            j = arr[inv[i]+1];
            while (((i+p) < n) && ((j+p) < n) && (s[i+p] == s[j+p])) p++;
        }
        lcp[inv[i]] = p;
        if (p > 0) p--;
    }
    for (i = 0; i < n-1; i++) sparse[i][0] = lcp[i];
    for (i = 1; (1 << i) <= n; i++) {
        for (j = 0; j <= n-(1 << i); j++) sparse[j][i] = min(sparse[j][i-1],sparse[j+(1 << (i-1))][i-1]);
    }
    for (i = 2; i <= n; i++) logg[i] = logg[i/2]+1;
    for (i = 2; i <= n; i++) {
        if (f[i].empty()) {
            for (j = i; j <= n; j += i) f[j].pb(i);
        }
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < n; j++) pre[i][j+1] = pre[i][j]+(s[j] == i+'a');
    }
    build(0,n-1,0);
    findReps(0,n-1);
    process(0,n-1,0);
    for (i = 0; i < n; i++) {
        rep2[i] = (i == 0) ? -1e9:rep2[i-1];
        if (repL[i] != 1e9) rep2[i] = max(rep2[i],i-repL[i]+1);
    }

    // -1
    for (i = 0; i < q; i++) {
        l = queries[i].l,r = queries[i].r;
        for (j = 0; j < 26; j++) {
            if (pre[j][r+1]-pre[j][l] > 1) break;
        }
        if (j == 26) ans[queries[i].i] = -1;
    }
    // 1
    for (i = 0; i < q; i++) {
        if (ans[queries[i].i] != 0) continue;
        l = queries[i].l,r = queries[i].r;
        for (j = 0; j < f[r-l+1].size(); j++) {
            int p = f[r-l+1][j];
            if (getLcp(l,l+(r-l+1)/p) >= (r-l+1)-(r-l+1)/p) break;
        }
        if (j < f[r-l+1].size()) ans[queries[i].i] = 1;
    }
    // 2 (case 1)
    for (i = 0; i < q; i++) {
        if (ans[queries[i].i] != 0) continue;
        l = queries[i].l,r = queries[i].r;
        if (min(repR[l],repL[r]) <= r-l+1) ans[queries[i].i] = 2;
    }
    // 2 (case 2)
    p = n;
    build2(0,n-1,0);
    for (i = 0; i < q; i++) {
        if (ans[queries[i].i] != 0) continue;
        l = queries[i].l,r = queries[i].r;
        int B = 3*sqrt(r-l+1);
        B = min(B,r-l);
        for (j = 1; j <= B; j++) {
            if (getLcp(l,r-j+1) >= j) break;
        }
        if (j <= B) ans[queries[i].i] = 2;
        else {
            int s = 0,e = inv[l];
            while (s < e) {
                int m = (s+e) / 2;
                if (getLcp(arr[m],l) < B) s = m+1;
                else e = m;
            }
            int ll = s;
            s = inv[l],e = n-1;
            while (s < e) {
                int m = (s+e+1) / 2;
                if (getLcp(arr[m],l) < B) e = m-1;
                else s = m;
            }
            int rr = e;
            while (p > l+1) p--,update2(0,n-1,inv[p],0,p);
            vi vv;
            while (1) {
                int q = query2(0,n-1,ll,rr,0);
                if (q > r) break;
                else vv.pb(q),update2(0,n-1,inv[q],0,1e9);
            }
            for (j = 0; j < vv.size(); j++) {
                if (getLcp(l,vv[j]) >= r-vv[j]+1) break;
            }
            if (j < vv.size()) ans[queries[i].i] = 2;
            for (j = 0; j < vv.size(); j++) update2(0,n-1,inv[vv[j]],0,vv[j]);
        }
    }
    // 3
    for (i = 0; i < q; i++) {
        if (ans[queries[i].i] != 0) continue;
        l = queries[i].l,r = queries[i].r;
        if (rep2[r] >= l) ans[queries[i].i] = 3;
        else if (pre[s[l]-'a'][r+1]-pre[s[l]-'a'][l] > 1) ans[queries[i].i] = 3;
        else if (pre[s[r]-'a'][r+1]-pre[s[r]-'a'][l] > 1) ans[queries[i].i] = 3;
    }
    // 4
    for (i = 0; i < q; i++) {
        if (ans[i] == 0) ans[i] = 4;
        printf("%d\n",ans[i]);
    }

    return 0;
}