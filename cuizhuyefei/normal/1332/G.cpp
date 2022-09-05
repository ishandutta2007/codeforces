#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n,q,a[N],sta1[N],top1,sta2[N],top2;
int insta[N],lst1[N],lst2[N];set<int>Set;
Vi ans3[N],ans4[N];
void print(Vi a){
	printf("%d\n",SZ(a));
	for(int x:a)printf("%d ",x);puts("");
}
void upd(int x){
	if(insta[x])Set.erase(x);else Set.insert(x);
}
int main() {
	read(n);read(q);
	rep(i,1,n)read(a[i]);
	rep(i,1,n+1)ans3[i].resize(3),ans3[i].back()=n+1;
	rep(i,1,n+1)ans4[i].resize(4),ans4[i].back()=n+1;
	int xy=0,dy=0;
	sta1[0]=sta2[0]=n+1;
	per(i,n,1){
		while(top1&&a[sta1[top1]]<a[i])insta[sta1[top1]]--,upd(sta1[top1]),top1--;
		sta1[++top1]=i;insta[i]++;
		lst1[top1]=a[sta1[top1]]!=a[sta1[top1-1]]?top1-1:lst1[top1-1];
		while(top2&&a[sta2[top2]]>a[i])insta[sta2[top2]]--,upd(sta2[top2]),top2--;
		sta2[++top2]=i;insta[i]++;
		lst2[top2]=a[sta2[top2]]!=a[sta2[top2-1]]?top2-1:lst2[top2-1];
		if(a[i]<=a[i+1])xy++;else xy=1;
		if(a[i]>=a[i+1])dy++;else dy=1;
		if(a[i]!=a[i+1]&&xy>1&&i+xy<ans3[i].back())ans3[i]={i,i+xy-1,i+xy};
		if(a[i]!=a[i+1]&&dy>1&&i+dy<ans3[i].back())ans3[i]={i,i+dy-1,i+dy};
		auto it=Set.lower_bound(max(sta1[lst1[top1]],sta2[lst2[top2]]));
		if(it!=Set.end()&&(*it)<ans4[i].back()){
			int x=*upper_bound(sta1+1,sta1+top1+1,*it,greater<int>());
			int y=*upper_bound(sta2+1,sta2+top2+1,*it,greater<int>());
			if(x>y)swap(x,y);
//			print({i,x,y,(*it)});
//			rep(i,1,top1)printf("%d ",sta1[i]);puts("");
//			rep(i,1,top2)printf("%d ",sta2[i]);puts("");
			assert(i<x&&x<y&&y<*it);
			ans4[i]={i,x,y,(*it)};
		}
		if(ans3[i+1].back()<ans3[i].back())ans3[i]=ans3[i+1];
		if(ans4[i+1].back()<ans4[i].back())ans4[i]=ans4[i+1];
	}
	while(q--){
		int l,r;read(l);read(r);
		if(r>=ans4[l].back()){
			print(ans4[l]);
		}
		else if(r>=ans3[l].back()){
			print(ans3[l]);
		}
		else puts("0");
	}
	return 0;
}