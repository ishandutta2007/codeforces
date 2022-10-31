#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                //xor:a[i+j]=x+y,a[i+j+d]=x-y;
	                //and:a[i+j]=x+y;
	                //or:a[i+j+d]=x+y;
	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
	                //and:a[i+j]=x-y;
	                //or:a[i+j+d]=y-x;
	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
const int Maxn=4e5+5;
char c[Maxn];
LL p[Maxn],s[Maxn];
LL basp[Maxn],bass[Maxn];
LL fact[Maxn];
int st;
int upp;
void add(int pos){
	while (pos>=0 && c[pos]=='z'){
		pos--;
	}
	if (pos==-1){
		printf("Impossible\n");
		exit(0);
	}
	c[pos]++;
	st=pos;
}
bool eq(int l,int d){
	if (l-d+1<0) return false;
	LL s1=p[l];
	if (l-d>=0) s1-=p[l-d];
	LL s2=s[l];
	
	if (l-d>=0) s2-=s[l-d];
	//cout<<l<<d<<endl;
	if (basp[l-d+1]>bass[l]){
		//cout<<basp[l-d+1]-bass[l]<<endl;
		s2*=fact[basp[l-d+1]-bass[l]];
	}
	else{
		//cout<<basp[l-d+1]-bass[l]<<endl;
		s1*=fact[-basp[l-d+1]+bass[l]];
	}
	//cout<<l<<d<<endl;
	return s1==s2;
}
void Update(int x){
	if (!x){
		s[x]=fact[bass[x]]*c[x];
		p[x]=fact[basp[x]]*c[x];
		return;
	}
	s[x]=s[x-1]+fact[bass[x]]*c[x];
	p[x]=p[x-1]+fact[basp[x]]*c[x];
}
int main(){
	fact[0]=1;
	for (int i=1;i<Maxn;i++){
		fact[i]=fact[i-1]*479;
	}
	int d;
	d=read();
	scanf("%s",c);
	int n=strlen(c);
	add(n-1);
	upp=st+1;
	for (int i=0;i<n;i++){
		basp[i]=i;
		bass[i]=n-i-1;
	} 
	//upp=1e9;
	if (d==1){
		printf("Impossible\n");
		return 0;
	}
	for (int i=0;i<n;i++){
		if (i>=upp) c[i]='a';
		Update(i);
		if (eq(i,d) || eq(i,d+1)){
			add(i);
			//cout<<i<<endl;
			i=st-1;
			upp=st+1;
		}
		//cout<<i<<endl;
	}
	printf("%s\n",c);
	return 0;
}
/*
4
abbabbbabbb
*/