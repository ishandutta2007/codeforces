#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=1000005;
int f0[N<<2],f1[N<<2],c0[N<<2],c1[N<<2],t[N<<2];
int n,m,x,y;
char s[N];

void up(int o){
	f0[o]=max(f0[lc]+c1[rc],c0[lc]+f0[rc]);
	f1[o]=max(f1[lc]+c0[rc],c1[lc]+f1[rc]);
	c0[o]=c0[lc]+c0[rc];
	c1[o]=c1[lc]+c1[rc];
}

void build(int o,int l,int r){
	if(l==r){
		if(s[l]=='4') c0[o]=1;
		else c1[o]=1;
		f0[o]=f1[o]=1;
		return;
	}
	build(lc,l,mid),build(rc,mid+1,r);
	up(o);
}

void app(int o){
	swap(f1[o],f0[o]);
	swap(c1[o],c0[o]);
	t[o]^=1;
}

void down(int o){
	if(!t[o]) return;
	app(lc),app(rc),t[o]=0;
}

void upd(int o,int l,int r,int x,int y){
	if(l==x&&y==r){
		app(o);
		return;
	}
	down(o);
	if(x<=mid) upd(lc,l,mid,x,min(y,mid));
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y);
	up(o);
}

int main(){
	read(n),read(m);
	scanf("%s",s+1);
	build(1,1,n);
	while(m--){
		static char op[5];
		scanf("%s",op);
		if(op[0]=='s'){
			read(x),read(y);
			upd(1,1,n,x,y);
		}
		else{
			printf("%d\n",f0[1]);
		}
	}
	return 0;
}