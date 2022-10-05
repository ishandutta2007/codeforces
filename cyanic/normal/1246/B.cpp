#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
const int mod1=998244353;
const int mod2=19260817;
map<pii,int> cnt;
int a[N],pw1[N][105],pw2[N][105];
int n,K,A1,A2,B1,B2;
ll ans;

void doit(int &x,int y){
	int k=0;
	if(y==1||x%y!=0)return;
	while(x%y==0)x/=y,k++;
	k%=K;
	A1=(A1+pw1[y][k])%mod1;
	A2=(A2+pw2[y][k])%mod2;
	k=(K-k)%K;
	B1=(B1+pw1[y][k])%mod1;
	B2=(B2+pw2[y][k])%mod2;
}

int Ran(){
	int res=0;
	rep(i,0,30)if(rand()&1)res|=1<<i;
	return res;
}

int main(){
	read(n),read(K);
	rep(i,1,100000)if(i==2||(i&1)){
		pw1[i][0]=pw2[i][0]=1;
		int A=Ran()%mod1,B=Ran()%mod2;
		rep(j,1,K){
			pw1[i][j]=(ll)pw1[i][j-1]*A%mod1;
			pw2[i][j]=(ll)pw2[i][j-1]*B%mod2;
		}
		rep(j,0,K){
			pw1[i][j]=(pw1[i][j]+mod1-1)%mod1;
			pw2[i][j]=(pw2[i][j]+mod2-1)%mod2;
		}
	}
	rep(i,1,n){
		A1=A2=B1=B2=0;
		read(a[i]);
		for(int j=2;j*j<=a[i];j++)
			if(a[i]%j==0)doit(a[i],j);
		if(a[i]>=2)doit(a[i],a[i]);
		// printf("%d %d %d %d\n",A1,A2,B1,B2);
		ans+=cnt[mp(B1,B2)];
		cnt[mp(A1,A2)]++;
	}
	cout<<ans<<endl;
	return 0;
}