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
const int N = 200020;
int n,a[N],pre[N],b[N],m,dp[N];Pii v[102000];//max,pos
int s[N],len;multiset<int>Set;
void put(int l,int r){
//	cerr<<"put "<<l<<' '<<r<<endl;
	int lst=a[l];
	rep(i,l,r)if(a[i]==-1){
		int x=*Set.upper_bound(lst);
	//	cerr<<x<<endl;
		if(x<a[r])a[i]=x,Set.erase(Set.find(x)),lst=x;
	}
}
int main() {
	read(n);rep(i,1,n)read(a[i]);a[++n]=0x3f3f3f3f;
	read(m);rep(i,1,m)read(b[i]);sort(b+1,b+m+1);
	rep(i,1,n)if(a[i]!=-1)s[++len]=a[i];rep(i,1,m)s[++len]=b[i];sort(s+1,s+len+1);
	len=unique(s+1,s+len+1)-s-1;
	rep(i,1,n)if(a[i]!=-1)a[i]=lower_bound(s+1,s+len+1,a[i])-s;
	rep(i,1,m)b[i]=lower_bound(s+1,s+len+1,b[i])-s;
	rep(i,1,n)v[i]=Pii(0x3f3f3f3f,0);
	rep(i,1,n)
		if(a[i]!=-1){
			int p=lower_bound(v+1,v+n+1,Pii(a[i],0))-v;
			pre[i]=v[p-1].se;v[p]=Pii(a[i],i);dp[i]=p;
		}
		else{
			for(int j=m,k=n;j>=1;j--){
				while(b[j]<=v[k-1].fi)k--;
				int r=j;while(r-1>=1&&b[r-1]>v[k-1].fi)r--;
				v[k]=Pii(b[r],v[k-1].se);j=r;
			}
		}
//	int res=0;rep(i,1,len)umax(res,v[i].fi);assert(res==dp[n]);//cerr<<res<<endl;
	rep(i,1,m)Set.insert(b[i]);Set.insert(0x3f3f3f3f);
	Vi c;for(int i=n;;i=pre[i]){c.pb(i);if(!i)break;}
//	rep(i,1,n)cerr<<pre[i]<<' ';cerr<<endl;
	rep(i,0,SZ(c)-2)put(c[i+1],c[i]);
	rep(i,1,n)if(a[i]==-1)a[i]=*Set.begin(),Set.erase(Set.begin());
	rep(i,1,n-1)printf("%d ",s[a[i]]);
	return 0;
}