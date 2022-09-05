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
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 1.1e6+11,mo=1e9+7;
void add(int &x, int y){x=(x+y)%mo;}
int n,cd[N],pos[N];
char t[N];
//struct SA {
	char s[N];
	int sa[N*2],rk[N*2],tt[N*2],buc[N],h[N],v[N][21],Log[N];
	inline void getsa() {
		memset(buc,0,sizeof(buc));
		memset(tt,0,sizeof(tt)); //WA2 !!!!!!!!!!!!!!!!!!!!!!!!!!
		memset(rk,0,sizeof(rk)); //WA3 !!!!!!!!!!!!!!!!!!!!!!!!!!
		rep(i,1,n) buc[s[i]]++;
		rep(i,1,256) buc[i]+=buc[i-1];
		per(i,n,1) sa[buc[s[i]]--]=i;
		rep(i,1,n) rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
		for (int j=1; j<n; j<<=1) {
			int h=0; rep(i,n-j+1,n) tt[++h]=i;
			rep(i,1,n) if (sa[i]-j>=1) tt[++h]=sa[i]-j;
			memset(buc,0,sizeof(buc));
			rep(i,1,n) buc[rk[i]]++;
			rep(i,1,n) buc[i]+=buc[i-1];
			per(i,n,1) sa[buc[rk[tt[i]]]--]=tt[i];
			rep(i,1,n) tt[sa[i]]=tt[sa[i-1]]+(rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i]+j]!=rk[sa[i-1]+j]);
			memcpy(rk,tt,sizeof(tt));
		}
		int p=0;
		rep(i,1,n) {
			if (p) p--; int j=sa[rk[i]-1];
			while (i+p<=n&&j+p<=n&&s[i+p]==s[j+p]) p++;
			h[rk[i]]=p; //WA1: h[sa[i]]=p is wrong!!!!!!!!!!!!!!!!
		}
		rep(i,1,n) v[i][0]=h[i];
		rep(j,1,20) rep(i,1,n-(1<<j)+1)
			v[i][j]=min(v[i][j-1],v[i+(1<<j-1)][j-1]);
		rep(i,1,n) {Log[i]=Log[i-1]; if ((1<<Log[i]+1)==i) Log[i]++;}
	}
	inline int getlcp(int l, int r) { //lcp([l,n] & [r,n])
		if(l==r)return n;
		l=rk[l]; r=rk[r]; if (l>r) swap(l,r); l++; int k=Log[r-l+1];
		return min(v[l][k],v[r-(1<<k)+1][k]);
	}
//} sa;
struct node{
	int l,r,x;
	bool operator<(node a)const{
		assert(l<=x&&x<=r&&a.l<=a.x&&a.x<=a.r);
		
		/*int n=r-l,m=a.r-a.l,p1=l,p2=a.l;
		rep(i,1,min(n,m)){
			if(p1==x)p1++;
			if(p2==a.x)p2++;
			if(s[p1]!=s[p2])return s[p1]<s[p2];
			p1++;p2++;
		}
		return n<m;*/
		
		if(l==r&&a.l==a.r)return 0;
		if(l==r)return 1;
		if(a.l==a.r)return 0;
		int L=l,R=r,X=x;
	//	cerr<<"qwq"<<L<<' '<<X<<' '<<R<<' '<<a.l<<' '<<a.x<<' '<<a.r<<endl;
		if(X>L&&a.x>a.l){
			int lcp=min(min(getlcp(L,a.l),X-L),a.x-a.l);
			L+=lcp;a.l+=lcp;
		//	cerr<<"qvvq"<<L<<' '<<X<<' '<<R<<' '<<a.l<<' '<<a.x<<' '<<a.r<<endl;
			if(X>L&&a.x>a.l)return s[L]<s[a.l];
		}
	//	cerr<<"qaq"<<L<<' '<<X<<' '<<R<<' '<<a.l<<' '<<a.x<<' '<<a.r<<endl;
		if(L==X&&a.l!=a.x){
			int lcp=min(min(getlcp(L+1,a.l),a.x-a.l),R-X);
			L++;L+=lcp;a.l+=lcp;
			if(L<=R&&a.l<a.x)return s[L]<s[a.l];
			L--;X=L;
		}
		if(a.l==a.x&&L!=X){
			int lcp=min(min(getlcp(L,a.l+1),X-L),a.r-a.x);
			a.l++;a.l+=lcp;L+=lcp;
			if(a.l<=a.r&&L<X)return s[L]<s[a.l];
			a.l--;a.x=a.l;
		}
	//	cerr<<"qvq"<<L<<' '<<X<<' '<<R<<' '<<a.l<<' '<<a.x<<' '<<a.r<<endl;
	
		assert(L<=X&&X<=R&&a.l<=a.x&&a.x<=a.r);
		if(L==R&&a.l==a.r)return 0;
		if(L==R)return 1;
		if(a.l==a.r)return 0;
	
		assert(L==X&&a.l==a.x&&L<=R&&a.l<=a.r);	
		L++;a.l++;
		int lcp=min(getlcp(L,a.l),min(R-L+1,a.r-a.l+1));
		L+=lcp;a.l+=lcp;
		if(L<=R&&a.l<=a.r)return s[L]<s[a.l];
		return R-L<a.r-a.l;
	}
};
//bool dcmp(node a, node b){return ((!(a<b))&&(!(b<a)));}
vector<node>f[233333];
Vi dp[233333];
//void print(node a){printf("[%d %d %d] ",a.l,a.x,a.r);rep(i,a.l,a.r)if(i!=a.x)putchar(s[i]);putchar(' ');}
int main() {
	int m;read(m);
	rep(i,1,m){
		scanf("%s",t+1);int len=strlen(t+1);
		pos[i]=n+1;cd[i]=len;
		rep(j,1,len)s[++n]=t[j];
	}
	pos[m+1]=n+1;
	s[++n]='#';
	getsa();
//	cout<<((node){1,2,3}<(node){1,3,3})<<endl;
	rep(i,1,m){
		rep(j,1,cd[i])f[i].pb((node){pos[i],pos[i+1]-1,pos[i]+j-1});
		f[i].pb((node){pos[i],pos[i+1],pos[i+1]});
		sort(ALL(f[i]));
		/*vector<node> tmp;
		tmp.pb(f[i][0]);
		rep(j,1,SZ(f[i])-1)if(!dcmp(f[i][j],tmp.back()))tmp.pb(f[i][j]);
		else print(tmp.back()),print(f[i][j]),puts("");
		f[i]=tmp;*/
		dp[i].resize(SZ(f[i]));
	}
	for(int &x:dp[1])x=1;
	int res=0;
	rep(i,2,m){
		int k=0,cur=0;
		rep(j,0,SZ(f[i])-1){
			while(k<SZ(f[i-1])&&!(f[i][j]<f[i-1][k]))add(cur,dp[i-1][k]),k++;
			dp[i][j]=cur;
		//	printf("%d %d:%d\n",i,j,cur);
		//	if(i==m)add(res,cur);
		}
	}
	for(int x:dp[m])add(res,x);
	cout<<res;
	return 0;
}