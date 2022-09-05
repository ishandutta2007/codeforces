#include<cstdio>
#include<cstring>
#include<ctime>
#include<set>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
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
int n,head,x,v,nxt;
set<int> Set;
unsigned int seed=613,now=1;
inline int Rand() {
	now=(now*seed>>3)^(now*seed<<7);
	return now%n+1;
}
int main() {
	srand(19260817);
	read(n); read(head); read(x);
	int pos=head,val=0;
	rep(i,1,min(n,1000)) {
		int p=Rand(); while (Set.count(p)) p=Rand();
		Set.insert(p); printf("? %d\n",p); fflush(stdout);
		read(v); read(nxt); if (v<=x&&v>val) {val=v; pos=p;}
	}
	rep(t,1,995) {
		printf("? %d\n",pos); fflush(stdout);
		read(val); read(nxt); 
		if (val>=x) {printf("! %d",val); fflush(stdout); return 0;}
		pos=nxt; if (pos==-1) break;
	}
	printf("! -1"); fflush(stdout); return 0;
}