#include<bits/stdc++.h>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


//#pragma GCC optimize(2)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=2e3+10,P=1e6+3;

int n;
int A[N];
char s[N];
ll dp[N][N];





int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	rep(i,1,len) {
		//if(isdigit(s[i]) && !isdigit(s[i-1])) A[++n]=0;
		if(!isdigit(s[i])) {
			//if(s[i]=='*'||s[i]=='/') A[++n]=2;
			//else 
			n++;
			if(s[i+1]=='+'||s[i+1]=='-') A[n]=1;
			if(s[i+1]=='/'||s[i+1]=='*') return puts("0"),0;
		}
	}
	if(s[1]=='*'||s[1]=='/'||!isdigit(s[len])) return puts("0"),0;
	dp[0][0]=1;
	rep(i,1,n) {
		rep(j,1,n+1) (dp[i-1][j]+=dp[i-1][j-1])%=P;
		if(A[i]==0) rep(j,0,n) dp[i][j]=dp[i-1][j+1];
		else rep(j,1,n) dp[i][j]=dp[i-1][j];
	}
	//rep(i,0,n) { 
		//drep(j,n,1) dp[i][j]-=dp[i][j-1];
		//rep(j,0,n) cout<<dp[i][j]<<' '; puts(""); 
	//}
	//rep(i,1,n) cout<<A[i]<<' ';puts("");
	printf("%lld\n",dp[n][0]);
}