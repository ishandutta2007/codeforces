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
const ll mo = 1e9;
struct bignum{
	ll a[100];int len;
	bignum(ll X=0){
		memset(a,0,sizeof(a));len=1;a[1]=X;
		while(a[len]>=mo)a[len+1]+=a[len]/mo,a[len]%=mo,len++;
	}
	void input(){
		static char s[1000];scanf("%s",s+1);
		for(ll i=strlen(s+1),j=1,k=1;i>=1;i--){
			a[j]+=k*(s[i]-'0');umax(len,(int)j);
			k*=10;if(k>=mo)k/=mo,j++;
		}
	}
	void operator =(const ll &x){
		memset(a,0,sizeof(a));len=1;a[1]=x;
		while(a[len]>=mo)a[len+1]+=a[len]/mo,a[len]%=mo,len++;
	}
	void operator +=(const bignum &x){
		umax(len,x.len);rep(i,1,x.len)a[i]+=x.a[i];
		rep(i,1,len)if(a[i]>=mo){a[i]-=mo;a[i+1]++;}
		if(a[len+1])len++;
	}
	void operator -=(const bignum &x){
		rep(i,1,len){
			a[i]-=x.a[i];if(a[i]<0)a[i]+=mo,a[i+1]--;
		}
		while(len>1&&!a[len])len--;
	}
	inline void Print(ll x){
		int sta[19];int len=0;
		while(x)sta[++len]=x%10,x/=10;if(!len)sta[++len]=0;//WA
		while(len)printf("%d",sta[len--]);
	}
	inline void print(){
		Print(a[len]);
		per(i,len-1,1)for(ll j=mo/10;j>=1;j/=10)printf("%lld",a[i]/j%10);//WA
	}
}n,a[90],b[90];
bignum operator -(bignum a, bignum b){
	rep(i,1,a.len){
		a.a[i]-=b.a[i];if(a.a[i]<0)a.a[i]+=mo,a.a[i+1]--;
	}
	while(a.len>1&&!a.a[a.len])a.len--;
	return a;
}
bool operator ==(bignum a, bignum b){
	if(a.len!=b.len)return 0;
	per(i,a.len,1)if(a.a[i]!=b.a[i])return 0;
	return 1;
}
bool operator >=(bignum a, bignum b){
	if(a.len!=b.len)return a.len>b.len;
	per(i,a.len,1)if(a.a[i]!=b.a[i])return a.a[i]>b.a[i];
	return 1;
}
bool operator <(bignum a, bignum b){
	if(a.len!=b.len)return a.len<b.len;
	per(i,a.len,1)if(a.a[i]!=b.a[i])return a.a[i]<b.a[i];
	return 0;
}
bignum operator *(bignum a, int x){
	rep(i,1,a.len)a.a[i]*=x;
	rep(i,1,a.len){
		int t=a.a[i]/mo;a.a[i+1]+=t;a.a[i]-=t*mo;
	}
	while(a.a[a.len+1]){a.len++;int t=a.a[a.len]/mo;a.a[a.len+1]+=t;a.a[a.len]-=t*mo;}
	while(a.len>1&&!a.a[a.len])a.len--;//WA: *0
	return a;
}
bignum operator <<(bignum a, int k){
	bignum b;b.len=a.len+k;
	rep(i,1,a.len)b.a[i+k]=a.a[i];return b;
}
bignum operator /(bignum a, bignum b){
	bignum res;int mx=a.len-b.len+1;assert(a.len==1||a.a[a.len]);
	per(i,mx,1){
		int l=0,r=(a.a[b.len+i-1]+1)/b.a[b.len]+1,tmp=0;r=mo-1;
		while(l<=r){
			int mid=(l+r)>>1;
			bignum c=(b<<i-1)*mid;if(a>=c)tmp=mid,l=mid+1;else r=mid-1;
		}
		if(tmp){a-=(b<<i-1)*tmp;umax(res.len,i);res.a[i]=tmp;}
	}
	return res;
}

bignum operator %(bignum a, bignum b){
	per(i,a.len-b.len+1,1){
		int l=0,r=mo-1,tmp=0;
		while(l<=r){
			int mid=(l+r)>>1;
			bignum c=(b<<i-1)*mid;if(a>=c)tmp=mid,l=mid+1;else r=mid-1;
		}
		a-=(b<<i-1)*tmp;
	}
	while(a.len>1&&!a.a[a.len])a.len--;//WA
	return a;
}
bignum div2(bignum a){
	per(i,a.len,1){
		if(a.a[i]&1)a.a[i]--,a.a[i-1]+=mo;a.a[i]>>=1;
	}
	while(a.len>1&&!a.a[a.len])a.len--;
	return a;
}
inline bignum GCD(bignum a, bignum b){
	if(b.len<=1&&b.a[1]==0)return a;
	if(!(a.a[1]&1)&&(!b.a[1]&1))return GCD(div2(a),div2(b))*2;
	if(!(a.a[1]&1))a=div2(a);if(!(b.a[1]&1))b=div2(b);
	if(a<b)swap(b,a);//a>=b
	return GCD(a-b,b);
}
int erci(bignum n, bignum x){
	while(1){
		ll i=R()%10000;
		bignum y=i*i;y=y%n;if(y==x)return i;
	}
	return -1;
}
set<bignum>qaaq;int len;
void dfs(bignum n, int d){
	if(n==1)return;
	if(d>len){
		qaaq.insert(n);
		return;
	}
	dfs(GCD(n,a[d]),d+1);
	dfs(GCD(n,b[d]),d+1);
}
int main() {
	/*n.input();ll x=2;bignum qaq=x*x;qaq=qaq%n;
	cout<<erci(n,qaq);
	return 0;*/
	n.input();
	while(len<14){
		ll x=R()%10000;
	//	printf("x=%d\n\n",x);
		printf("sqrt ");bignum qaq=x*x;qaq=qaq%n;
		bignum(qaq).print();puts("");fflush(stdout);
		bignum y,g,X;X=x;
		
		y.input();
	//	y=erci(n,qaq);
		
		
		y+=X;g=GCD(n,y);
		if(len<20&&!(g==1||g==n)){
			len++;a[len]=g;b[len]=n/g;
		}
	}
	
	dfs(n,1);
	
	//cerr<<len<<endl;
	bignum res[90];int sz=0;
	for(set<bignum>::iterator it=qaaq.begin();it!=qaaq.end();it++)res[++sz]=*it;
	
	/*bignum need=n;
	rep(s,0,(1<<len)-1)if(!(need==1)){
		//if(s%500==0)cerr<<s<<' '<<debug<<endl;
		bignum now=n;
		rep(i,1,len)if(!(now==1)){if(s>>i-1&1)now=GCD(now,a[i]);else now=GCD(now,b[i]);}
		if(!(now==1)){
			bool find=0;
			rep(i,1,sz)find|=(res[i]==now);
			if(!find)res[++sz]=now,need=need/now;
		}
	}*/
	printf("! ");printf("%d ",sz);rep(i,1,sz)res[i].print(),putchar(' ');
	fflush(stdout);
	return 0;
}