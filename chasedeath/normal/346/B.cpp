#include<cstdio> 
#include<cstring> 
#include<cctype>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

/*
void Exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){ 
		x=1,y=0;
		return;
	}
	Exgcd(b,a%b,y,x);y-=a/b*x;
}
*/

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0;
	while(!isdigit(IO=getchar()));
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return s;
}


//const ll P=19260817,K=5567891;
//const ll P1=1e9+13,K1=6550879;
const int N=1e2+10;

int n,m,k;

char a[N],b[N],p[N];
int nxt[N];
int dp[N][N][N];
struct node{
	int a,b,c;
	char d;
} pre[N][N][N];
int t[N],c;


int main(){
	scanf("%s%s%s",a+1,b+1,p+1);
	n=strlen(a+1),m=strlen(b+1);
	rep(i,2,k=strlen(p+1)) {
		int j=nxt[i-1];
		while(j && p[i]!=p[j+1]) j=nxt[j];
		if(p[i]==p[j+1]) nxt[i]=j+1;
		else nxt[i]=0;
		//nxt[i]=j;
	}
	//rep(i,1,k) printf("%d ",nxt[i]);puts("");
	int ans=0,ai=-1,aj=-1,ao=-1;
	rep(i,0,n) {
		rep(j,0,m) {
			rep(o,0,k-1) {
				if(a[i+1]==b[j+1]&&i<n&&(dp[i][j][o]||o==0)) {
					int t=o;
					while(t && a[i+1]!=p[t+1]) t=nxt[t];
					if(a[i+1]==p[t+1]) t++;
					//if(i==4&&j==4&&o==4) cout<<"!"<<o<<' '<<p[o+1]<<' '<<a[i+1]<<' '<<t<<endl;
					if(dp[i+1][j+1][t]<dp[i][j][o]+1&&(dp[i][j][o]||o==0)){
						dp[i+1][j+1][t]=dp[i][j][o]+1;
						//cout<<"#"<<a[i+1]<<' '<<i+1<<' '<<j+1<<' '<<o<<' '<<t<<' '<<dp[i+1][j+1][t]<<endl;
						pre[i+1][j+1][t]=(node){i,j,o,a[i+1]};
					}
				}
				if(dp[i+1][j][o]<dp[i][j][o]) {
					dp[i+1][j][o]=dp[i][j][o];
					pre[i+1][j][o]=(node){i,j,o,-1};
					//if(i==2&&j==3&&o==0) cout<<"Upd "<<i+1<<' '<<j<<' '<<o<<' '<<dp[i][j][o]<<endl;
				}
				if(dp[i][j+1][o]<dp[i][j][o]) {
					dp[i][j+1][o]=dp[i][j][o];
					pre[i][j+1][o]=(node){i,j,o,-1};
					//if(i==3&&j==2&&o==0) cout<<"Upd "<<i<<' '<<j+1<<' '<<o<<' '<<dp[i][j][o]<<endl;
				}
				if(ans<dp[i][j][o]) ans=dp[i][j][o],ai=i,aj=j,ao=o;
			}
		}
	}
	if(!ans) return puts("0"),0;
	//cout<<ans<<endl;
	while(dp[ai][aj][ao]) {
		//cout<<ai<<' '<<aj<<' '<<ao<<' '<<dp[ai][aj][ao]<<' ';
		if(~pre[ai][aj][ao].d) t[++c]=pre[ai][aj][ao].d;
		//cout<<pre[ai][aj][ao].d<<endl;
		int i=pre[ai][aj][ao].a;
		int j=pre[ai][aj][ao].b;
		int o=pre[ai][aj][ao].c;
		ai=i,aj=j,ao=o;
	}
	drep(i,c,1) putchar(t[i]);
}