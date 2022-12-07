#include <bits/stdc++.h>
#include <ext/rope>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

char a[100005],b[100005];
int bb[100005];
struct node {
    node* l, * r, * p;
    int cnt, val;
    bool inv,rev;
    node():node(0){}
    node(int _val) :
        cnt(1), val(_val), inv(false), rev(false),
        l(nullptr), r(nullptr), p(nullptr) {
    }
}*root;

void Lazy(node* x)
{
    if (!x->inv) return;
    x->rev = !x->rev;
    swap(x->l, x->r);
    x->inv = false;
    if (x->l) x->l->inv = !x->l->inv;
    if (x->r) x->r->inv = !x->r->inv;
}
void update(node* x) 
{
    x->cnt = 1;
    if (x->l) {
        x->cnt += x->l->cnt;
    }
    if (x->r) {
        x->cnt += x->r->cnt;
    }
}

void rotate(node* x)
{
    node* p = x->p;
    node* b = nullptr;
	Lazy(p);
	Lazy(x);
    if (x == p->l) {
        p->l = b = x->r;
        x->r = p;
    }
    else {
        p->r = b = x->l;
        x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if (b) b->p = p;
    x->p ? (p == x->p->l ? x->p->l : x->p->r) = x : (root = x);
    update(p);
    update(x);
}

void splay(node* x)
{
    while (x->p) {
        node* p = x->p;
        node* g = p->p;
        if (g) rotate((x == p->l) == (p == g->l) ? p : x);
        rotate(x);
    }
}


void find_kth(int k) 
{
    node* x = root;
    Lazy(x);
    while (true) {
        while (x->l && x->l->cnt > k) {
            x = x->l;
            Lazy(x);
        }
        if (x->l) k -= x->l->cnt;
        if (!k--) break;
        x = x->r;
        Lazy(x);
    }
    splay(x);
}

node* interval(int l, int r)
{
    find_kth(l - 1);
    node* x = root;
    root = x->r;
    root->p = nullptr;
    find_kth(r - l + 1);
    x->r = root;
    root->p = x;
    root = x;
    return root->r->l;
}

void reverse(int l,int r)
{
	node* p=interval(l,r);
	p->inv = !p->inv;
}
void init(int n) {
	node *x;
	int i;
	root = x = new node;
	x->l = x->r = x->p = NULL;
	x->cnt = n;
	x->val = 0;
	x->inv=0;
	for (i = 1; i < n; i++)
	{
		x->r = new node;
		x->r->p = x;
		x = x->r;
		x->l = x->r = NULL;
		x->cnt = n - i;
		x->val = a[i]-'0';
		x->inv=0;
	}
}
void solve(){
	int n;
	scanf("%d",&n);
	scanf("%s%s",a+1,b+1);
	a[n+1]='0';
	fup(i,1,n,1)bb[i]=b[i]-'0';
	init(n+2);
	Vi ans;
	fdn(i,n,1,1){
		find_kth(i);
		if(root->val ^ root->rev == bb[i])continue;
		find_kth(1);
		if(root->val ^ root->rev == bb[i]){
			ans.pb(1);
			root->val ^= 1;
		}
		ans.pb(i);
		reverse(1,i);
	}
	printf("%d ",ans.size());
	for(int x:ans)printf("%d ",x);
		puts("");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}