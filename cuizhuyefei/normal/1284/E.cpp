#include<bits/stdc++.h>
#define x first
#define y second
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
#define pi acos(-1)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<long double,ll> Pdi;
typedef pair<ll,ll> Pii;
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
const int N = 666666;
ll len,n;ll res;
Pii a[N];Pdi s[N];
ll Cross(Pii x, Pii y){return 1ll*x.x*y.y-1ll*x.y*y.x;}
Pii Gdot(int i, int j){return Pii(a[i].x-a[j].x,a[i].y-a[j].y);}
int main() {
	read(n);rep(i,1,n)read(a[i].x),read(a[i].y);
	rep(j,1,n){
		len=0;rep(i,1,n)if(i!=j)s[++len]=Pdi(atan2(a[i].y-a[j].y,a[i].x-a[j].x),i);
		res+=1ll*len*(len-1)*(len-2)*(len-3)/24;
		sort(s+1,s+len+1);rep(i,1,len)s[len+i]=s[i],s[len+i].fi+=pi*2;//+pi*2;
		for(int i=1,k=1;i<=len;i++){
			while(k+1<=2*len&&(s[k+1].fi-s[i].fi<=pi+1e-5&&Cross(Gdot(s[i].se,j),Gdot(s[k+1].se,j))>0||k+1<=i))k++;
		//	printf("%d:%d %d %lf\n",j,i,k,s[k].fi-s[i].fi);
			int q=k-i;
			if(q>=3)res-=1ll*q*(q-1)*(q-2)/6;
		}
	}
	cout<<res;
	return 0;
}