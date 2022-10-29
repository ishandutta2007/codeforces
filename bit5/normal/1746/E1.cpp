#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use in interactive problems!!! 
	return getchar();
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc();
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7, mod=998244353;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
inline int query(vector<int>S) {
	cout<<"? "<<S.size()<<" ";
	for (int x:S) cout<<x<<" "; cout<<endl;
	string s; cin>>s;
	return s=="YES"?1:0;
}
inline void answer(int x) {
	cout<<"! "<<x<<endl;
	string s; cin>>s;
 	if (s==":)") exit(0);
}
void solve(vector<int>vec) {
	if ((int)vec.size()<=3) {
		int sz=vec.size();
		if (sz==1) answer(vec[0]);
		else if (sz==2) answer(vec[0]), answer(vec[1]);
		else {
			int x=vec[0], y=vec[1], z=vec[2];
			int a=query({x, y});
			if (!a) {
				int b=query({x});
				if (!b) solve({y, z});
				else solve({x, z});
			}
			a=query({z});
			if (!a) solve({x, y});
			a=query({y, z});
			if (a==1) solve({y, z});
			else solve({x, z});
		}
		return;
	}
	int sz=vec.size();
	int m=sz/2, lm=m/2, rm=(m+sz)/2;
	vector<int>A(vec.begin(), vec.begin()+m);
	int x=query(A);
	if (x==1) {
		vector<int>B(vec.begin()+m, vec.begin()+rm);
		int y=query(B);
		if (y==1) solve(vector<int>(vec.begin(), vec.begin()+rm));
		else {
			for (int i=rm; i<sz; i++) A.push_back(vec[i]);
			solve(A);
		}
	} else {
		vector<int>B(vec.begin(), vec.begin()+lm);
		int y=query(B);
		if (!y) solve(vector<int>(vec.begin()+lm, vec.end()));
		else {
			A=vector<int>(vec.begin()+m, vec.end());
			for (int i=0; i<lm; i++) A.push_back(vec[i]);
			solve(A);
		}
	}
}
int n;
inline void work() {
	n=read();
	vector<int>vec(n);
	iota(vec.begin(), vec.end(), 1);
	solve(vec);
}
int main() {
//#ifndef ONLINE_JUDGE
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
//#endif
	int test=1; //read();
	while (test--) work();
	return 0;
}