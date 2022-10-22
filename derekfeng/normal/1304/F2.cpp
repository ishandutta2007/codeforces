#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0'); 
}
int n,m,K,d[53][20004],dp[53][20004],m_=1,ans,cnt[66000],dat[66000];
void init(int l,int r,int id){
	cnt[id]=0;
	if (l==r) return;
	init(l,(l+r)/2,id*2+1),init((l+r)/2+1,r,id*2+2);
	dat[id]=max(dat[id*2+1],dat[id*2+2]);
}
void upd(int l,int r,int id,int a,int b,int add_){
	if (r<l) return;
	if (r<a || b<l) return;
	if (a<=l && r<=b){
		dat[id]+=add_;
		cnt[id]+=add_;
		return;
	}
	upd(l,(l+r)/2,id*2+1,a,b,add_),upd((l+r)/2+1,r,id*2+2,a,b,add_),dat[id]=max(dat[id*2+1],dat[id*2+2])+cnt[id];
}
int main(){
	read(n),read(m),read(K);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) read(d[i][j]),d[i][j]+=d[i][j-1];
	while (m_<m-K+1) m_<<=1;
	for (int i=1;i+K-1<=m;i++) dp[1][i]=d[1][i+K-1]-d[1][i-1];
	for (int i=2;i<=n;i++){
		for (int j=1;j+K-1<=m;j++){
			dat[j+m_-2]=dp[i-1][j];
			if (K>=j) dat[j+m_-2]+=d[i][j+K-1];
			else dat[j+m_-2]+=d[i][j+K-1]-d[i][j-1]+d[i][K];
		} 
		init(0,m_-1,0);
		dp[i][1]=dat[0];
		for (int j=2;j+K-1<=m;j++){
			upd(0,m_-1,0,0,j-K-2,-d[i][j-1]+d[i][j-2]),upd(0,m_-1,0,j-1,m-K,-d[i][j-1]+d[i][j-2]);
			upd(0,m_-1,0,0,j-2,d[i][j+K-1]-d[i][j+K-2]),upd(0,m_-1,0,j+K-1,m-K,d[i][j+K-1]-d[i][j+K-2]);
			dp[i][j]=dat[0];
		}
	}
	for (int i=1;i+K-1<=m;i++) ans=max(ans,dp[n][i]);
	write(ans);
}