#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=1e9+7;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
const mint inv2=(mod+1)/2;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define int long long
const int N=4e3+10;
int p=114514,a;string A;
struct bigint{
	vector<int>num;
	int size(){return num.size();}
	void resize(int x){num.resize(x);}
	int&operator[](int x){return num[x];}
	void kk(){
		for(int i=0;i+1<size();i++)num[i+1]+=num[i]/p,num[i]%=p;
		while(num.back()>=p)
			num.pb(num.back()/p),num[num.size()-2]%=p;
	}
	bigint(int a=0){resize(1);num[0]=a;kk();}
	friend bigint operator*(bigint a,int b){
		for(int i=0;i<a.size();i++)a[i]*=b;
		a.kk();return a;
	}
	friend bigint operator+(bigint a,bigint b){
		a.resize(max(a.size(),b.size()));
		for(int i=0;i<b.size();i++)a[i]+=b[i];
		a.kk();return a;
	}
}L;
mint dp[N][N][2][2];
signed main(){
	read(p,a);cin>>A;
	reverse(A.begin(),A.end());
	bigint tmp(1);
	for(int i=0;i<(int)A.size();i++,tmp=tmp*10)
		L=L+tmp*(int)(A[i]-'0');
	vector<int>X=L.num;reverse(X.begin(),X.end());
	dp[0][0][0][0]=1;
	for(int i=0;i<(int)X.size();i++){
		int x=X[i];
		for(int j=0;j<(int)X.size();j++){
			dp[i+1][j][0][0]+=dp[i][j][0][0]*(x+1);
			dp[i+1][j][1][0]+=dp[i][j][0][0]*(x+1)*x*inv2;
			dp[i+1][j+1][0][1]+=dp[i][j][0][0]*x;
			dp[i+1][j+1][1][1]+=dp[i][j][0][0]*x*(x-1)*inv2;
			dp[i+1][j][0][0]+=dp[i][j][0][1]*(p-x-1);
			dp[i+1][j][1][0]+=dp[i][j][0][1]*x*(2*p-x-1)*inv2;
			dp[i+1][j+1][0][1]+=dp[i][j][0][1]*(p-x);
			dp[i+1][j+1][1][1]+=dp[i][j][0][1]*x*(2*p-x+1)*inv2;
			dp[i+1][j][1][0]+=dp[i][j][1][0]*(p+1)*p*inv2;
			dp[i+1][j+1][1][1]+=dp[i][j][1][0]*p*(p-1)*inv2;
			dp[i+1][j][1][0]+=dp[i][j][1][1]*p*(p-1)*inv2;
			dp[i+1][j+1][1][1]+=dp[i][j][1][1]*(p+1)*p*inv2;
		}
	}
	mint ans=0;
	for(int i=a;i<=(int)X.size();i++)
		ans+=dp[X.size()][i][0][0]+dp[X.size()][i][1][0];
	writeln(ans.x);
}