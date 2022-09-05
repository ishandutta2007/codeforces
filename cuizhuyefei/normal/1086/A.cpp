#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1050;
int n=1000,x[5],y[5];
int a,b,res=1e9;
int Abs(int x){return x>0?x:-x;}
int main() {
	rep(i,1,3)read(x[i]),read(y[i]);
	rep(i,0,n)rep(j,0,n){
		int now=0;rep(c,1,3)now+=Abs(x[c]-i)+Abs(y[c]-j);
		if(now<res)res=now,a=i,b=j;
	}
	set<Pii>Set;
	rep(i,1,3)Set.insert(Pii(x[i],y[i]));
	rep(i,1,3){
		int c=x[i],d=y[i];
		//a,b <-- c,d
		while(c<a)c++,Set.insert(Pii(c,d));
		while(c>a)c--,Set.insert(Pii(c,d));
		while(d<b)d++,Set.insert(Pii(c,d));
		while(d>b)d--,Set.insert(Pii(c,d));
	}
	printf("%d\n",SZ(Set));
	while(SZ(Set)){
		printf("%d %d\n",(*Set.begin()).fi,(*Set.begin()).se);
		Set.erase(Set.begin());
	}
	return 0;
}