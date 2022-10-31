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
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
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
const int Maxn=55;
int n,m;
string s[Maxn][Maxn];
int id[Maxn][Maxn];
int f(char c){
	if (c=='A') return 0;
	if (c>='2' && c<='9') return c-'1';
	if (c=='T') return 9;
	if (c=='J') return 10;
	if (c=='Q') return 11;
	if (c=='K') return 12;
}
int ff(char c){
	if (c=='C') return 0;
	if (c=='D') return 13;
	if (c=='H') return 26;
	return 39;
}
int Getr(string t){
	if (t=="J1") return 52;
	if (t=="J2") return 53;
	return ff(t[1])+f(t[0]);
}
char fuck[15]="A23456789TJQK";
string tr(int v){
	int xx=v/13;
	string r;
	if (!xx) r+='C';
	else if (xx==1) r+='D';
	else if (xx==2) r+='H';
	else r+='S';
	r+=fuck[v%13];
	swap(r[0],r[1]);
	return r;
}
int x1,y1,x2,y2;
bool use[15];
bool check(int x,int y){
	bool flag=true;
	for (int i=x;i<=x+2;i++){
		for (int j=y;j<=y+2;j++){
			if (id[i][j]/13!=id[x][y]/13){
				flag=false;
				break;
			}
		}
	}
	if (flag) return true;
	memset(use,0,sizeof(use));
	for (int i=x;i<=x+2;i++){
		for (int j=y;j<=y+2;j++){
			if (use[id[i][j]%13]){
				return false;
			}
			use[id[i][j]%13]=1;
		}
	}
	return true;
}
void Get(){
	x1=y1=x2=y2=-1;
	for (int i=1;i<=n-2;i++){
		for (int j=1;j<=m-2;j++){
			if (!check(i,j)) continue;
			for (int k=i;k<=n-2;k++){
				for (int l=1;l<=m-2;l++){
					if (k-i<3 && abs(l-j)<3) continue;
					if (check(k,l)){
						x1=i,y1=j,x2=k,y2=l;
						return;
					}
				}
			}
		}
	}
}
int jx1,jy1,jx2,jy2;
bool hav[Maxn];
int main(){
	cin>>n>>m;
	int msk=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>s[i][j];
			id[i][j]=Getr(s[i][j]);
			if (id[i][j]==52) msk++,jx1=i,jy1=j;
			if (id[i][j]==53) msk+=2,jx2=i,jy2=j;
		}
	}
	if (!msk){
		Get();
		if (x1==-1){
			puts("No solution.");
		}
		else{
			puts("Solution exists.");
			puts("There are no jokers.");
			printf("Put the first square to (%d, %d).\n",x1,y1);
			printf("Put the second square to (%d, %d).\n",x2,y2);
		}
		return 0;
	}
	if (msk==1 || msk==2){
		int X,Y;
		int jid;
		if (msk==1) X=jx1,Y=jy1,jid=1;
		else X=jx2,Y=jy2,jid=2;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				hav[id[i][j]]=true;
			}
		}
		for (int i=0;i<52;i++){
			if (!hav[i]){
				id[X][Y]=i;
				Get();
				if (x1!=-1){
					puts("Solution exists.");
					printf("Replace J%d with %s.\n",jid,tr(i).c_str());
					printf("Put the first square to (%d, %d).\n",x1,y1);
					printf("Put the second square to (%d, %d).\n",x2,y2);
					return 0;
				}
			}
		}
		puts("No solution.");
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			hav[id[i][j]]=true;
		}
	}
	for (int i=0;i<52;i++){
		for (int j=0;j<52;j++){
			if (i==j || hav[i] || hav[j]) continue;
			id[jx1][jy1]=i;
			id[jx2][jy2]=j;
			Get();
			if (x1!=-1){
				puts("Solution exists.");
				printf("Replace J1 with %s and J2 with %s.\n",tr(i).c_str(),tr(j).c_str());
				printf("Put the first square to (%d, %d).\n",x1,y1);
				printf("Put the second square to (%d, %d).\n",x2,y2);
				return 0;
			}
		}
	}
	puts("No solution.");
	return 0;
}