#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;

#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define rep1(i,a,b) for(int i = (a);i < (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define dwn1(i,a,b) for(int i = (a);i > (b);i --)
#define rev(i,a) for(int i = 0;i < a.size();i ++)
#define reu(i,a) for(int i = h[a];~i;i = n1[i])

template <class T> inline void read(T &x){
    char ch = getchar();    int f = 1;  while((ch != '-') && (ch < '0' || ch > '9'))    ch = getchar();
    if(ch == '-')   f = 0, x = 0;   else    x = ch - 48;
    ch = getchar(); while(ch >= '0' && ch <= '9')   x = x * 10 + ch - 48, ch = getchar();
    if(!f)  x = -x;
}
template <class T> inline void read(T &x,T &y){read(x);read(y);}
template <class T> inline void read(T &x,T &y,T &z){read(x);read(y);read(z);}
template <class T> inline void read(T &x,T &y,T &z,T &o){read(x);read(y);read(z);read(o);}

int _t[20];
template <class T> inline void out(T x,int ln = 1){
    if(!x)  putchar('0');
    else{
        if(x < 0)   putchar('-'),x = -x;
        for(_t[0] = 0;x;x /= 10)    _t[++ _t[0]] = x % 10;
        dwn(i,_t[0],1)  putchar(_t[i] + 48);
    }
    if(ln == 2) putchar(' ');
    else    if(ln == 1) putchar('\n');
}

#define N 200010
int bit[N], n, a[N], b[N];
int f[N], g[N];

void add(int x, int d){
	for(;x <=n ;x += x&-x) bit[x]+=d;
}
int ask(int x){
	int ret =0;
	for(;x;x -=x&-x)ret+=bit[x];
	return ret;
}

int main(){
	read(n);
	rep(i,1,n)add(i,1);
	rep(i,1,n){
		read(a[i]);
		f[i]=ask(a[i]);
		a[i]++;
		add(a[i],-1);
	}
	rep(i,1,n)add(i,1);
	rep(i,1,n){
		read(a[i]);
		g[i]=ask(a[i]);
		a[i]++;
		add(a[i],-1);
	}
	rep(i,1,n) f[i]+=g[i];
	dwn(i,n-1,1){
		f[i-1]+=f[i]/(n-i+1);
		f[i]%=(n-i+1);
	}
	rep(i,1,n)add(i,1);
	rep(i,1,n){
		int l=1,r=n,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(ask(mid)<=f[i]) l=mid+1; else r=mid-1;
		}
		add(l,-1);
		printf("%d%c",l-1,(i==n)?'\n':' ');
	}
			
			
	return 0;
}