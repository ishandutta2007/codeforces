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
const int N = 13;
int bel[N];
void move(Vi a){
	printf("next ");
	rep(i,0,SZ(a)-1)printf("%d ",a[i]);
	puts("");fflush(stdout);
	int t,x;read(t);
	int num=0;
	while(t--){
		char s[16];scanf("%s",s+1);int len=strlen(s+1);
		num++;
		rep(i,1,len)bel[s[i]-'0']=num;
	}
}
int main() {
	while(1){
		Vi b;b.pb(1);move(b);
		Vi a;a.pb(1);a.pb(2);move(a);
		if(bel[1]==bel[2])break;
	}
	while(1){
		Vi a;a.pb(1);a.pb(3);move(a);
		if(bel[1]==bel[2])break;
	}
	Vi a;rep(i,3,9)a.pb(i);a.pb(0);bool flag=0;
	if(!flag&&bel[1]==bel[3]){flag=1;a.pb(1);a.pb(2);}
	while(1){
		move(a);
		if(!flag&&bel[1]==bel[3]){flag=1;a.pb(1);a.pb(2);}
		bool s=1;rep(i,1,9)s&=bel[0]==bel[i];
		if(s)break;
	}
	puts("done");fflush(stdout);
	return 0;
}