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
const int N = 333333;
int n,v[11][11][4][100020];char s[N];
int dy(char c){
	return c=='A'?0:(c=='C'?1:(c=='T'?2:3));
}
int TOT;
inline void add(int *v, int p, int xs){
	while(p<=TOT)v[p]+=xs,p+=p&-p;
}
inline int query(int *v, int p){int res=0;while(p)res+=v[p],p-=p&-p;return res;}
void modify(int p, int c, int xs){
	rep(i,1,10){
		TOT=n/i+1;int j=p%i;add(v[i][j][c],p/i+1,xs);
	}
}
int main() {
	scanf("%s",s+1);n=strlen(s+1);rep(i,1,n)modify(i,dy(s[i]),1);
	int q;read(q);
	while(q--){
		int op;read(op);
		if(op==1){
			int x;char t[3];scanf("%d%s",&x,t);
			modify(x,dy(s[x]),-1);s[x]=t[0];modify(x,dy(s[x]),1);
		}
		else{
			int l,r;read(l);read(r);char t[13];scanf("%s",t);int len=strlen(t);
			int res=0;
			rep(i,0,len-1){
				int L=l+i,R=L+(r-L)/len*len;if(L>r)continue;
				res+=query(v[len][L%len][dy(t[i])],R/len+1)-query(v[len][L%len][dy(t[i])],L/len);
			}
			printf("%d\n",res);
		}
	}
	return 0;
}