#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 50005;
int n,k;
struct node {
	int size; int m[13],M[13];
	inline void merge(node a) {
		size+=a.size;
		rep(i,1,k) {m[i]=min(m[i],a.m[i]); M[i]=max(M[i],a.M[i]);}
	}
	bool operator < (const node &a) const {
		rep(i,1,k) if (M[i]>a.m[i]) return 0;
		return 1;
	}
} a[N];
set<node> Set;
set<node> ::iterator it,it1;
inline void query() {it=Set.end(); it--; printf("%d\n",(*it).size);}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(k); rep(i,1,n) rep(j,1,k) {read(a[i].m[j]); a[i].M[j]=a[i].m[j];}
	rep(i,1,n) {
		a[i].size=1;
		it=Set.lower_bound(a[i]); node u=*it; 
		if (it==Set.end() || a[i]<u) {Set.insert(a[i]); query(); continue;}
		u.merge(a[i]);
		while (it!=Set.end()) {
		//	printf("%d %d\n",(*it).m[1],(*it).m[2]);
			it1=it; it++; Set.erase(it1);
			if (it==Set.end()) break;
			if (u<*(it)) break;
			u.merge(*it);
		}
		Set.insert(u);
		query();
	}
	return 0;
}