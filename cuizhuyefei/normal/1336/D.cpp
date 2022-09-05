#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 155;
int n,ori[N],d[N];//ori=a, cur=a+d
int f[N],g[N],cnt,lst1,lst2;
void ope(int x){
	printf("+ %d\n",x);fflush(stdout);
	int a,b;read(a);read(b);
	++cnt;f[cnt]=a-lst1;g[cnt]=b-lst2;
	lst1=a;lst2=b;
	d[x]++;
}
int C3(int x){return x*(x-1)*(x-2)/6;}
int main() {
	read(n);int A,B;read(A);read(B);f[0]=A;g[0]=B;lst1=A;lst2=B;
	ope(2);
	ope(1);
	ope(3);
	ope(1);
	while(C3(ori[1]+2)-C3(ori[1]+1)!=f[4])ori[1]++;
	if(g[2]){ori[3]=1;while(C3(ori[3]+1)-C3(ori[3])!=f[3])ori[3]++;}
	if(ori[3])ori[2]=(g[2])/ori[3]-1;else ori[2]=g[4]-1;
	ori[4]=g[3]/(ori[2]+1)-1-ori[1];
	int cur=4;
	if(n>4&&!ori[3]){
		int tmp=g[3]-(ori[2]+1)*(ori[1]+1);int C=ori[2]+1;
		if(!tmp){ori[4]=0;}
		else{
			ope(2);
			ori[4]=g[cnt]/(ori[3]+1)-ori[1]-2;
			assert(ori[4]);
			ori[5]=tmp/ori[4]-C;
			cur=5;
		}
	}else if(n>4)ori[4]=g[1]/ori[3]-ori[1];
	while(cur<n){
		if(ori[cur]+d[cur]){
			ope(cur-1);
			ori[cur+1]=g[cnt]-(ori[cur-2]+d[cur-2])*(ori[cur]+d[cur]+ori[cur-3]+d[cur-3]);
			ori[cur+1]/=ori[cur]+d[cur];
			cur++;continue;
		}
		ope(cur);
		int tmp=g[cnt]-(ori[cur-2]+d[cur-2])*(ori[cur-1]+d[cur-1]);
		if(!tmp){ori[cur+1]=0;cur++;continue;}
		if(cur+1==n){ori[cur+1]=tmp/(ori[cur-1]+d[cur-1]);cur++;continue;}
		ope(cur+1);ori[cur+1]=1;while(C3(ori[cur+1]+1)-C3(ori[cur+1])!=f[cnt])ori[cur+1]++;
		ori[cur+2]=tmp/ori[cur+1]-(ori[cur-1]+d[cur-1]);
		cur+=2;
	}
	printf("! ");rep(i,1,n)printf("%d ",ori[i]);fflush(stdout);
	return 0;
}