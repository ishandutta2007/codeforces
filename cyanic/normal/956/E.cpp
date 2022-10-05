#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef bitset<10005> bits;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=10005;
int x[N],y[N],s[N],a[N],b[N];
int n,m,c,l,r;
bits f;

int main(){
	read(n),read(l),read(r);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	rep(i,1,n){
		if(b[i]==0) x[++m]=a[i];
		else y[++c]=a[i];
	}
	f.set(0);
	rep(i,1,m) f|=f<<x[i];
	sort(y+1,y+c+1);
	rep(i,1,c) s[i]=s[i-1]+y[i];
	bits g;
	per(i,c,1){
		g=f|(g<<y[i]);
		int k=g._Find_next(l-1);
		if(k+s[i-1]<=r){
			printf("%d\n",i);
			return 0;
		}
		f|=f<<y[i];
	}
	puts("0");
	return 0;
}