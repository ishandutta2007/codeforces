#include<bits/stdc++.h>
using namespace std;
void chmin(int &A,int B){if(A>B)A=B;}
int f[4003][4003];
int ti,td,tr,te,n,m;
char s[4003],t[4003];
int nxta[4003][26],nxtb[4003][26];
int main(){
	scanf("%d%d%d%d%s%s",&ti,&td,&tr,&te,s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=0;i<26;i++)nxta[n+1][i]=n+1,nxtb[m+1][i]=m+1;
	for(int i=n;i;i--){
		memcpy(nxta[i],nxta[i+1],104);
		nxta[i][s[i]-'a']=i;
	}
	for(int i=m;i;i--){
		memcpy(nxtb[i],nxtb[i+1],104);
		nxtb[i][t[i]-'a']=i;
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){
		if(i<n)chmin(f[i+1][j],f[i][j]+td);
		if(j<m)chmin(f[i][j+1],f[i][j]+ti);
		if(i<n&&j<m)chmin(f[i+1][j+1],f[i][j]+(s[i+1]==t[j+1]?0:tr));
		if(i<n-1&&j<m-1){
			int X=nxta[i+2][t[j+1]-'a'],Y=nxtb[j+2][s[i+1]-'a'];
			if(X<=n&&Y<=m)chmin(f[X][Y],f[i][j]+te+(X-i-2)*td+(Y-j-2)*ti);
		}
	}
	printf("%d",f[n][m]);
}