// : caigou
// : 2022-02-24 12:18

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e5+10,B=2.5e4;
using bt=bitset<B+1>;
int n,m;int ans=2e9+1;
struct node{
	int a[5],w;
	int&operator[](int x){return a[x];}
	bool operator<(const node rhs)const{return w<rhs.w;}
}a[N];
bt b;
void calc(int l,int r){
	unordered_map<int,bt>kk;
	for(int i=l;i<=r;i++)
		for(int j=0;j<m;j++)
			kk[a[i][j]][i-l]=1;
	for(int i=1,p;i<=n;i++)if(a[1].w+a[i].w<ans){
		b.set();
		for(int j=0;j<m;j++){
			if(kk.count(a[i][j]))b&=~kk[a[i][j]];
			p=b._Find_first();
			if(l+p>r)break;
		}
		if(l+p<=r)chkmn(ans,a[i].w+a[l+p].w);
	}
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)read(a[i][j]);
		read(a[i].w);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i+=B)calc(i,min(i+B-1,n));
	write(ans<=2e9?ans:-1);
}