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

int MOD;
struct SegmentTree {
    int tree[1 << 18],lazy[1 << 18];
    int prop(int s,int e,int i) {
        tree[i] = ((LLI) tree[i]*lazy[i]) % MOD;
        if (s != e) {
            lazy[2*i+1] = ((LLI) lazy[2*i+1]*lazy[i]) % MOD;
            lazy[2*i+2] = ((LLI) lazy[2*i+2]*lazy[i]) % MOD;
        }
        lazy[i] = 1;
        return 0;
    }
    int build(int s,int e,int i) {
        if (s == e) {
            lazy[i] = 1,tree[i] = 0;
            return 0;
        }

        int mid = (s+e) / 2;
        build(s,mid,2*i+1),build(mid+1,e,2*i+2);
        lazy[i] = 1,tree[i] = 0;
        return 0;
    }
    int update(int s,int e,int as,int ae,int i,int num) {
        prop(s,e,i);
        if ((s > ae) || (e < as)) return 0;
        else if ((s >= as) && (e <= ae)) {
            lazy[i] = ((LLI) lazy[i]*num) % MOD;
            prop(s,e,i);
            return 0;
        }

        int mid = (s+e) / 2;
        update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
        tree[i] = (tree[2*i+1] + tree[2*i+2]) % MOD;
        return tree[i];
    }
    int update1(int s,int e,int ai,int i,int num) {
        prop(s,e,i);
        if ((s > ai) || (e < ai)) return 0;
        else if (s == e) {
            tree[i] = num;
            return 0;
        }

        int mid = (s+e) / 2;
        update1(s,mid,ai,2*i+1,num),update1(mid+1,e,ai,2*i+2,num);
        tree[i] = (tree[2*i+1] + tree[2*i+2]) % MOD;
        return tree[i];
    }
    int query(int s,int e,int qs,int qe,int i) {
        prop(s,e,i);
        if ((s > qe) || (e < qs)) return 0;
        else if ((s >= qs) && (e <= qe)) return tree[i];

        int mid = (s+e) / 2;
        return (query(s,mid,qs,qe,2*i+1) + query(mid+1,e,qs,qe,2*i+2)) % MOD;
    }
};
struct SegmentTree2 {
    int tree[1 << 18],lazy[1 << 18];
    int prop(int s,int e,int i) {
        tree[i] += lazy[i]*(e-s+1);
        if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
        lazy[i] = 0;
        return 0;
    }
    int build(int s,int e,int i) {
        if (s == e) {
            lazy[i] = tree[i] = 0;
            return 0;
        }

        int mid = (s+e) / 2;
        build(s,mid,2*i+1),build(mid+1,e,2*i+2);
        lazy[i] = tree[i] = 0;
        return 0;
    }
    int update(int s,int e,int as,int ae,int i,int num) {
        prop(s,e,i);
        if ((s > ae) || (e < as)) return 0;
        else if ((s >= as) && (e <= ae)) {
            lazy[i] += num;
            prop(s,e,i);
            return 0;
        }

        int mid = (s+e) / 2;
        update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
        tree[i] = tree[2*i+1] + tree[2*i+2];
        return tree[i];
    }
    int query(int s,int e,int qs,int qe,int i) {
        prop(s,e,i);
        if ((s > qe) || (e < qs)) return 0;
        else if ((s >= qs) && (e <= qe)) return tree[i];

        int mid = (s+e) / 2;
        return query(s,mid,qs,qe,2*i+1) + query(mid+1,e,qs,qe,2*i+2);
    }
};
int a[100000];
vi primes,num;
SegmentTree arr,arr2;
SegmentTree2 fac[10];
int inv(int n) {
    LLI temp;
	LLI r = n,pr = MOD;
	LLI s = 0,ps = 1;
	LLI t = 1,pt = 0;
	while (r > 0) {
		int q = pr / r;
		temp = r,r = pr - q*r,pr = temp;
		temp = s,s = ps - q*s,ps = temp;
		temp = t,t = pt - q*t,pt = temp;
	}
	pt %= MOD;
	if (pt < 0) pt += MOD;
	return pt;
}
int main() {
    int i,j;
    int n,q;
    int t,l,r,x;
    scanf("%d %d",&n,&MOD);
    int m = MOD;
    for (i = 2; i*i <= m; i++) {
        if ((m % i) == 0) {
            primes.pb(i),num.pb(0);
            while ((m % i) == 0) num.back()++,m /= i;
        }
    }
    if (m != 1) primes.pb(m),num.pb(1);
    arr.build(0,n-1,0),arr2.build(0,n-1,0);
    for (i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        arr.update1(0,n-1,i,0,a[i]);
        int t = a[i];
        for (j = 0; j < primes.size(); j++) {
            int c = 0;
            while ((t % primes[j]) == 0) c++,t /= primes[j];
            fac[j].update(0,n-1,i,i,0,c);
        }
        printVar(t);
        arr2.update1(0,n-1,i,0,t);
    }
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d %d",&l,&r,&x),l--,r--;
            arr.update(0,n-1,l,r,0,x);
            int t = x;
            for (j = 0; j < primes.size(); j++) {
                int c = 0;
                while ((t % primes[j]) == 0) c++,t /= primes[j];
                fac[j].update(0,n-1,l,r,0,c);
            }
            printVar(t);
            arr2.update(0,n-1,l,r,0,t);
        }
        else if (t == 2) {
            scanf("%d %d",&l,&x),l--;
            int y = arr2.query(0,n-1,l,l,0);
            printVar(y);
            for (j = 0; j < primes.size(); j++) {
                int c = 0;
                while ((x % primes[j]) == 0) c++,x /= primes[j];
                int z = fac[j].query(0,n-1,l,l,0)-c;
                fac[j].update(0,n-1,l,l,0,-c);
                int b = primes[j];
                while (z > 0) {
                    if (z & 1) y = ((LLI) y*b) % MOD;
                    z >>= 1;
                    b = ((LLI) b*b) % MOD;
                }
            }
            printVar(y);
            x = inv(x);
            arr2.update(0,n-1,l,l,0,x);
            y = ((LLI) y*x) % MOD;
            arr.update1(0,n-1,l,0,y);
        }
        else {
            scanf("%d %d",&l,&r),l--,r--;
            printf("%d\n",arr.query(0,n-1,l,r,0));
        }
    }

    return 0;
}