#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;
int n,a[N],qz[N],hz[N],pos[N];

priority_queue<int>heap,era;
int sta[N],dep[N],top;
void ini(){
	while(!heap.empty())heap.pop();
	while(!era.empty())era.pop();
	top=0;
}
void ins(int x){
	int mx=0;
	while(top&&sta[top]>x)era.push(dep[top]),umax(mx,dep[top]),top--;
	sta[++top]=x;dep[top]=max(mx+1,top);heap.push(dep[top]);
}
int Gettop(){
	while(era.size()&&heap.size()&&heap.top()==era.top())
		heap.pop(),era.pop();
	return heap.top();
}
int main() {
	read(n);rep(i,1,n)read(a[i]),pos[a[i]]=i;
	if(n==1){printf("1 0");return 0;}
	static int tmp[N];
	int p=0;rep(i,1,n)if(a[i]==1)p=i;
	rep(i,1,n)tmp[i]=a[p+i-1<=n?p+i-1:p+i-1-n];
	rep(i,1,n)a[i]=tmp[i];
	ini();rep(i,2,n)ins(a[i]),qz[i]=Gettop();
	ini();per(i,n,2)ins(a[i]),hz[i]=Gettop();
	int res=1e9,pp=2;
	rep(i,1,n-1)umin(res,1+max(qz[i],hz[i+1]));
	rep(i,1,n-1)if(res==1+max(qz[i],hz[i+1]))pp=pos[a[i+1]]-1;
	printf("%d %d\n",res,pp);
	return 0;
}