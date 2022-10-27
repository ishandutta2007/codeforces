#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

typedef long long ll;
const int M = 998244353;
const int FACTN = 300000 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int add(int a, int b, int c) {
  return add(add(a, b), c);
}

int mul(int a, int b, int c) {
  return mul(mul(a, b), c);
}

int add(int a, int b, int c, int d) {
  return add(add(a, b, c), d);
}

int mul(int a, int b, int c, int d) {
  return mul(mul(a, b, c), d);
}

int add(int a, int b, int c, int d, int e) {
  return add(add(a, b, c, d), e);
}

int mul(int a, int b, int c, int d, int e) {
  return mul(mul(a, b, c, d), e);
}

int add(int a, int b, int c, int d, int e, int f) {
  return add(add(a, b, c, d, e), f);
}

int mul(int a, int b, int c, int d, int e, int f) {
  return mul(mul(a, b, c, d, e), f);
}

int add(int a, int b, int c, int d, int e, int f, int g) {
  return add(add(a, b, c, d, e, f), g);
}

int mul(int a, int b, int c, int d, int e, int f, int g) {
  return mul(mul(a, b, c, d, e, f), g);
}

int add(int a, int b, int c, int d, int e, int f, int g, int h) {
  return add(add(a, b, c, d, e, f, g), h);
}

int mul(int a, int b, int c, int d, int e, int f, int g, int h) {
  return mul(mul(a, b, c, d, e, f, g), h);
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

void dvup(int& a, int b) {
  a = dv(a, b);
}

int fact[FACTN], ifact[FACTN];

void computeFACT() {
  fact[0] = 1;
  for (int i = 1; i < FACTN; i++) fact[i] = mul(fact[i - 1], i);
  ifact[FACTN - 1] = dv(1, fact[FACTN - 1]);
  for (int i = FACTN - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
}

int getCOMB(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		int c0=0,c1=0;
		for (int i=0;i<n;i++){
		cin>>a[i];
		c0+=(a[i]==0);
		c1+=(a[i]==1);
		}
		int bdf=0,bds=0;
		for (int i=0;i<c0;i++){
	bdf+=(a[i]==1);	
}
for(int i=c0;i<n;i++){
bds+=(a[i]==0);
}
assert(bds==bdf);
int bd=bds;
int oth1=c0-bd,oth2=c1-bd;
assert(oth1+2*bd+oth2==n);
int e=0;
for (int r=1;r<=bd;r++){
	// r remaining
	oth1=c0-r;
	oth2=c1-r;
	assert(oth1+2*r+oth2==n);
	int ewait=0;
	int gd=(1LL*r*r)%M;
	int total=(1LL*n*(n-1)/2)%M;
	int pgood=dv(gd,total);

	ewait=dv(1,pgood);
	addup(e,ewait);
}
cout<<e<<"\n";
	}

	return 0;
}

 
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */