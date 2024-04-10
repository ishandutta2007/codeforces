#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define reu(i,a) for(int i = h[a];~i;i = n1[i])

typedef long long ll;
typedef long double db;

template <class T> inline void read(T &x){
	char ch = getchar();	int f = 1;	while((ch != '-') && (ch < '0' || ch > '9'))	ch = getchar();
	if(ch == '-')	f = 0, x = 0;	else	x = ch - 48;
	ch = getchar(); while(ch >= '0' && ch <= '9')	x = x * 10 + ch - 48, ch = getchar();
	if(!f)	x = -x;
}
template <class T> inline void read(T &x,T &y){read(x);read(y);}
template <class T> inline void read(T &x,T &y,T &z){read(x);read(y);read(z);}
template <class T> inline void read(T &x,T &y,T &z,T &o){read(x);read(y);read(z);read(o);}

int _t[20];
template <class T> inline void out(T x,int ln = 1){
	if(!x)	putchar('0');
	else{
		if(x < 0)	putchar('-'),x = -x;
		for(_t[0] = 0;x;x /= 10)	_t[++ _t[0]] = x % 10;
		dwn(i,_t[0],1)	putchar(_t[i] + 48);
	}
	if(ln)	putchar('\n');
}

/*...........................................................................................................*/

char str[6][27] = {
	{'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+'},
	{'|','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','|','D','|',')'},
	{'|','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','|','.','|'},
	{'|','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','#','.','|','.','|',')'},
	{'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+'}
};
int l[]={26,27,26,26,27,26};
pair<int,int> a[35];
int main(){
	a[1] = mp(1,1);
	a[2] = mp(2,1);
	a[3] = mp(3,1);
	a[4] = mp(4,1);
	rep(i,1,10){
		a[5 + i * 3 - 3] = mp(1,i * 2 + 1);
		a[5 + i * 3 - 2] = mp(2,i * 2 + 1);
		a[5 + i * 3 - 1] = mp(4,i * 2 + 1);
	}
	int n;
	read(n);
	rep(i,1,n)	str[a[i].fi][a[i].se] = 'O';
	rep(i,0,5){
		rep(j,0,l[i] - 1)	putchar(str[i][j]);
		if(i != 5)	putchar('\n');
	}
		
	return 0;
}