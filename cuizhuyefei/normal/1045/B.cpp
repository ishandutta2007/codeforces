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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 866666;
int n,m,a[N],v[N],p[N];Vi Set;
void manacher(int n){//v[1..n]
	per(i,n,1)v[i*2]=v[i],v[i*2+1]=-1;v[1]=-1;
	int id=0;
//	rep(i,1,n*2+1)printf("%d ",a[i]);puts("");
//	rep(i,1,n*2+1)printf("%d ",v[i]);puts("");
	rep(i,1,n*2+1){
		if(id*2-i>=1&&id+p[id]>=i)p[i]=min(p[id*2-i],id+p[id]-i);
		while(i+p[i]<=n*2+1&&i-p[i]>=1&&v[i+p[i]]==v[i-p[i]])p[i]++;
		if(p[i]+i>p[id]+id)id=i;//printf("%d:%d\n",i,p[i]);
		if(i-p[i]+1==3&&(i+p[i]-1)/2>=n/2){
		//	printf("val = %d + %d\n",a[1],a[(i+p[i]-1)/2]);
			Set.pb((1LL*a[1]+a[(i+p[i]-1)/2])%m);
		}
	}
}
int main() {
	read(n);read(m);rep(i,1,n)read(a[i]);rep(i,1,n)a[i+n]=a[i]+m;
	rep(i,1,n+n)v[i]=a[i]-a[i-1];v[1]=-233;//!!
	manacher(n+n);
	sort(Set.begin(),Set.end());
	Set.erase(unique(Set.begin(),Set.end()),Set.end());
	printf("%d\n",SZ(Set));rep(i,0,SZ(Set)-1)printf("%d ",Set[i]);
	return 0;
}