#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define pb push_back
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
const int N=4e5+100,M=460;
int n,m;
int x[N],y[N],t[N];
int kk[M][M];// i  i  j 
int cha[N],sum=0;
void mdf(int id,int op,int day){
	if(x[id]+y[id]<M){
		for(int i=x[id];i<x[id]+y[id];i++)
			kk[x[id]+y[id]][(t[id]+i)%(x[id]+y[id])]+=op;
	}
	else{
		for(ll now=t[id];now+x[id]<=m;now+=x[id]+y[id]){
			cha[now+x[id]]+=op;
			if(now+x[id]+y[id]<=m)cha[now+x[id]+y[id]]-=op;
			if(now+x[id]<day&&day<=now+x[id]+y[id])
				sum+=op;
		}
	}
}
int qry(int day){
	int res=0;sum+=cha[day];
	for(int i=1;i<M;i++)
		res+=kk[i][day%i];
	return res+sum; 
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(x[i],y[i]);
	for(int i=1;i<=m;i++){
		int op,x;read(op,x);
		if(op==1)t[x]=i,mdf(x,1,i);
		else mdf(x,-1,i);
		write(qry(i));putchar('\n');
	}
}