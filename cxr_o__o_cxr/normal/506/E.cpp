//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,fl=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')fl=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return fl==1?x:-x;
}
#define ll long long
const int N=304,mod=10007;
inline int fix(int x){
	return x+((x>>31)&mod);
} 
inline int add(int x,int y){
	return fix(x+y-mod);
}
inline int dec(int x,int y){
	return fix(x-y);
}
inline int mul(int x,int y){
	return (ll)x*y%mod;
}
inline void ADD(int &x,int y){
	x=fix(x+y-mod);
}
inline void DEC(int &x,int y){
	x=fix(x-y);
}
inline void MUL(int &x,int y){
	x=(ll)x*y%mod;
}
int n,m,k,ans[N],Ans[N],h[N][N][N];
char s[N];
struct matrix{
	int a[N][N];
	inline matrix operator *(const matrix &x)const{
		static matrix ret;
		for(int i=1;i<=k;i++)
			for(int j=i;j<=k;j++){
				ret.a[i][j]=0;
				for(int o=i;o<=j;o++)
					ADD(ret.a[i][j],mul(a[i][o],x.a[o][j]));
			}
		return ret;
	}
}A,AA;
inline void mul(){
	static int tmp[N];
	for(int i=1;i<=k;i++){
		tmp[i]=0;
		for(int j=1;j<=k;j++)
			ADD(tmp[i],mul(ans[j],A.a[j][i]));
	}
	memcpy(ans,tmp,sizeof(tmp));
}
inline void ksm(int r){
	for(int i=0;(1ll<<i)<=r;i++){
		if((r>>i)&1)mul();
		A=A*A;
	}
}
inline int H(int i,int l,int r){
	if(i<0)return 0;
	if(h[i][l][r]!=-1)return h[i][l][r];
	if(l==1&&r==m)return h[i][l][r]=!i;
	int ret=0;
	if(l!=1&&s[l-1]!=s[r])ADD(ret,H(i-1,l-1,r));
	if(r!=m&&s[l]!=s[r+1])ADD(ret,H(i-1,l,r+1));
	if(l!=1&&r!=m&&s[l-1]==s[r+1])ADD(ret,H(i,l-1,r+1));
	return h[i][l][r]=ret;
}
int main(){
	scanf("%s",s+1);m=strlen(s+1);
	n=read();k=m+((m+1)>>1);
	memset(h,-1,sizeof(h));
	for(int i=0,c;i<m;i++){
		c=0;
		for(int j=1;j<=m;j++){
			ADD(c,H(i,j,j));
			if(j!=m&&s[j]==s[j+1])c+=H(i,j,j+1);
		}
		if(i){
			A.a[i][k-((m-i+1)>>1)]=c;
			A.a[i][i]=24;
			if(i!=1)A.a[i-1][i]=1;
			else ans[i]=1;
		}
		else{
			ans[m]=c;A.a[k][k]=26;
			for(int j=m;j<k;j++){A.a[j][j+1]=1;A.a[j][j]=25;}
		}
	}
	if((n+m)&1){
		memcpy(Ans,ans,sizeof(ans));
		AA=A;
	}
	ksm((n+m+1)>>1);
	if(!(n+m)&1){cout<<ans[k];return 0;}
	int res=ans[k];
	memcpy(ans,Ans,sizeof(Ans));
	A=AA;
	for(int i=0,c;i<m;i++){
		c=0;
		for(int j=1;j<=m;j++)
			if(j!=m&&s[j]==s[j+1])ADD(c,H(i,j,j+1));
		if(i)A.a[i][k-((m-i+1)>>1)]=c;
		else{ans[m]=c;A.a[k][k]=0;}
	}
	ksm((n+m+1)>>1);
	cout<<dec(res,ans[k]);
	return (0-0);
}