#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for (int i(l);i<=int(r);++i)
#define per(i,l,r) for (int i(r);i>=int(l);--i)
typedef long long ll;
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}

int n,L;
char s[1000010],_s[1000010];

struct C{
	int ch[26];
	int fil,len,g,ffil,d,tot;
}c[1000010]; int ctot=1,lstid=1;

int getfil(int x){
	for (;s[L-c[x].len-1]!=s[L];x=c[x].fil);
	return x;
}

void ins(int d){
	int p=getfil(lstid);
	if (c[p].ch[d]==0){
		int v=++ctot;
		c[v].len=c[p].len+2;
		int t=getfil(c[p].fil);
		c[v].fil=c[t].ch[d];
		t=c[v].fil;
		c[v].d=c[v].len-c[t].len;
		if (t&&c[v].d==c[t].d) c[v].ffil=c[t].ffil,c[v].tot=c[t].tot+1;
		else c[v].ffil=t,c[v].tot=1;
		c[p].ch[d]=v;
//		printf("link %d -> %d\n",p,v);
	}
	lstid=c[p].ch[d];
}

int f[1000010];

int main()
{
	scanf("%s",_s+1); int _n=strlen(_s+1),_m=_n>>1;
	rep(i,1,_m) s[++n]=_s[_m-i+1],s[++n]=_s[_m+i];
//	puts(s+1); //!!!
	s[0]=100; rep(i,1,n) s[i]-='a';
	c[0].fil=1,c[0].len=0,c[1].fil=0,c[1].len=-1;
	f[0]=1;
	rep(i,1,n){
//		printf("test %d\n",i);
		L=i; ins(s[i]);
		for (int u=lstid;u>1;u=c[u].ffil){
			c[u].g=f[i-c[c[u].ffil].len-c[u].d];
			if (c[u].fil^c[u].ffil) add(c[u].g,c[c[u].fil].g);
//			printf("  test g %d: %d\n",u,c[u].g);
			if (!(i&1)) add(f[i],c[u].g);
		}
//		printf("done %d\n",i);
//		printf("test f %d = %d\n",i,f[i]);
//		rep(j,0,ctot) printf("  node %d: %d %d %d %d\n",j,c[j].fil,c[j].ffil,c[j].d,c[j].g);
//		puts("");
	}
	printf("%d\n",f[n]);
	return 0;
}