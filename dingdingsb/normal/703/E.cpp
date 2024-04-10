#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
typedef long long ll;
int n;const int N=1000+100;
long long k,a[N],b[N];
vector<ll>A;//
map<ll,int>S;//
pair<int,ll>dp[N][7000+10]; 
signed main(){
	in::read(n,k);
	for(int i=1;i<=n;i++)
		in::read(a[i]),b[i]=__gcd(a[i],k);
	if(k==1)return printf("%d\n%d",1,min_element(a+1,a+1+n)-a),0;
	for(int i=1;i<=sqrt(k);i++)
		if(k%i==0)
			A.push_back(i),
			A.push_back(k/i);
	sort(A.begin(),A.end());
	A.resize(unique(A.begin(),A.end())-A.begin());
    for(int i=0;i<A.size();i++)S[A[i]]=i;
	for(int i=1;i<A.size();i++)dp[0][i]={0x3f3f3f3f,0};
	for(int i=1;i<=n;i++){
		for(int j=0;j<A.size();j++){
			ll pre=S[A[j]/__gcd(A[j],b[i])];
			dp[i][j]={dp[i-1][pre].first+1,dp[i-1][pre].second+a[i]};
			dp[i][j]=min(dp[i][j],dp[i-1][j]);
		}
	}if(dp[n][A.size()-1].first>n)return puts("-1"),0;
	out::write(dp[n][A.size()-1].first);
	out::putc('\n');
	for(int i=n;i>=1;i--)
		if(dp[i][S[k]]!=dp[i-1][S[k]])
			out::write(i),
			out::putc(' '),
			k/=__gcd(k,b[i]);
	out::flush();
	return 0;
}