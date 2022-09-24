//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

const int N=200010;
int n,m;
pii h[N];
int res[N],rem[N];

struct item {
    int key=0, prior, ind, prop=0, val=0, valprop=0;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;

void push(pitem a)
{
	if (!a) return;
	//cout<<(a->ind)<<' '<<(a->key)<<' '<<(a->val)<<' '<<(a->prop)<<' '<<(a->valprop)<<endl;
	a->key+=a->prop;
	a->val+=a->valprop;
	if (a->l)
	{
		a->l->prop+=a->prop;
		a->l->valprop+=a->valprop;
	}
	if (a->r)
	{
		a->r->prop+=a->prop;
		a->r->valprop+=a->valprop;
	}
	a->prop=0;
	a->valprop=0;
}

void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else
	{
		push(t);
		if (key < t->key)
        	split (t->l, key, l, t->l),  r = t;
   		else
        	split (t->r, key, t->r, r),  l = t;
	}
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}

pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt, rt;
    push(l);
    split (r, l->key, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else
	{
		push(t);
		push(it);
		if (it->prior > t->prior)
        	split (t, it->key, it->l, it->r),  t = it;
    	else
        	insert (it->key < t->key ? t->l : t->r, it);
    }
}

void trav(pitem t)
{
	if (!t) return;
	push(t);
	res[t->ind]=t->val;
	rem[t->ind]=t->key;
	trav(t->l);
	trav(t->r);
}

void prc(pitem t)
{
	if (!t) return;
	push(t);
	cout<<(t->ind)<<' '<<(t->key)<<endl;
	prc(t->l);
	prc(t->r);
}

void ins(pitem a,pitem&t)
{
	if (!a) return;
	push(a);
	if (a->l) ins(a->l,t);
	if (a->r) ins(a->r,t);
	a->l=NULL;
	a->r=NULL;
	insert(t,a);
}

item ne[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i].y>>h[i].x;
		h[i].x*=-1;
	}
	sort(h,h+n);
	cin>>m;
	pitem t=ne;
	for (int i=0;i<m;++i)
	{
		int a;
		cin>>a;
		ne[i].prior=rand();
		ne[i].key=a;
		ne[i].ind=i;
		if (i) insert(t,ne+i);
	}
	for (int i=0;i<n;++i)
	{
		pitem a0=ne+m,a1=ne+m+1;
		//cout<<"splitting to <"<<h[i].y<<" and >"<<h[i].y<<endl;
		split(t,h[i].y-1,t,a0);
		//cout<<"t:"<<endl;
		//prc(t);
		//cout<<"a0:"<<endl;
		//prc(a0);
		if (a0)
		{
			a0->prop-=h[i].y;
			a0->valprop+=1;
		}
		//cout<<"splitting(again) to <"<<h[i].y<<" and >"<<h[i].y<<endl;
		split(a0,h[i].y-1,a0,a1);
		//cout<<"a0:"<<endl;
		//prc(a0);
		//cout<<"a1:"<<endl;
		//prc(a1);
		//cout<<"uniting t and a0."<<endl;
		ins(a0,t);
		//cout<<"t:"<<endl;
		//prc(t);
		//cout<<"merging t and a1."<<endl;
		merge(t,t,a1);
		//cout<<"t:"<<endl;
		//prc(t);
	}
	trav(t);
	for (int i=0;i<m;++i) cout<<res[i]<<' ';
	cout<<en;
	//for (int i=0;i<m;++i) cout<<rem[i]<<' ';
	//cout<<en;
}