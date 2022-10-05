#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;

const int N=2005,mod=1e9+7;
void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int lcp[2][N][N],rlcp[2][N][N],f[2][N][N];
char s[2][N],t[N];
int n,m,res;

void solve(){
	REP(k,2){
		per(i,n-1,0)per(j,m-1,0)
			if(s[k][i]==t[j])lcp[k][i][j]=lcp[k][i+1][j+1]+1;
			else lcp[k][i][j]=0;
		per(i,n-1,0)REP(j,m)
			if(s[k][i]==t[j])rlcp[k][i][j]=(j?rlcp[k][i+1][j-1]:0)+1;
			else rlcp[k][i][j]=0;
	}
	if(m%2==0){
		int len=m/2;
		rep(i,len-1,n-1){
			if(rlcp[0][i-len+1][len-1]>=len
			  &&lcp[1][i-len+1][len]>=len)
			  	add(res,1);
		}
		if(len>=2)
		rep(i,0,n-len){
			if(lcp[0][i][0]>=len
			&&rlcp[1][i][m-1]>=len)
			  	add(res,1);
		}
	}
	memset(f,0,sizeof f);
	REP(i,2)REP(j,n){
		if(s[i][j]==t[0]&&s[i][j+1]==t[1])
			f[i][j+1][1]++;
		rep(len,1,(m-1)/2)if(j-len+1>=0)
			if(rlcp[i][j-len+1][len-1]>=len
			&&lcp[1-i][j-len+1][len]>=len+1)
				f[1-i][j+1][len*2]++;
	}
	REP(j,n)REP(i,2)REP(k,m)
		if(f[i][j][k]){
			if(s[i][j+1]==t[k+1])
				add(f[i][j+1][k+1],f[i][j][k]);
			if(s[1-i][j]==t[k+1]&&s[1-i][j+1]==t[k+2])
				add(f[1-i][j+1][k+2],f[i][j][k]);
		}
	REP(i,2)REP(j,n){
		add(res,f[i][j][m-1]);
		rep(len,1,m/2){
			int k=m-2*len;
			if(lcp[i][j][k]>=len
			&&rlcp[1-i][j][m-1]>=len)
				add(res,f[i][j][k]);
		}
	}
}

int main(){
	scanf("%s%s%s",s[0],s[1],t);
	n=strlen(s[0]),m=strlen(t);
	if(m==1){
		REP(i,2)REP(j,n)res+=(s[i][j]==t[0]);
		return cout<<res<<endl,0;
	}
	solve();
	if(m>=2)reverse(t,t+m),solve();
	cout<<res<<endl;
	return 0;
}