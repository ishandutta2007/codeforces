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
const int N=30004,mod=1e9+7;
int n,m,tot=1,ch[N][10],tg[N],fail[N],f[52][N],pw10[52];
queue<int>q;
inline void getfail(){
	for(int i=0;i<10;i++)ch[0][i]=1;
	q.push(1);
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int c=0;c<10;c++){
			if(!ch[p][c])ch[p][c]=ch[fail[p]][c];
			else{
				fail[ch[p][c]]=ch[fail[p]][c];
				q.push(ch[p][c]);
			}
		}
	}
}
int solve(char *s,int len,int p,int fl){
//	cerr<<len<<" "<<p<<" "<<fl<<"\n";
	if(!fl&&f[len][p]!=-1)return f[len][p];
	if(!fl&&tg[p])return f[len][p]=pw10[m-len+1];
	if(tg[p]){
		int ret=0;
		for(int i=len;i<=m;i++)ret=((ll)ret*10+s[i]-'0')%mod;
		return ret+1;
	}
	if(len>m)return 0;
	int ret=0,mx=fl?s[len]-'0':9;
	for(int i=0;i<=mx;i++){
		ret=(ret+solve(s,len+1,ch[p][i],fl&&i==mx))%mod;
	}
	if(!fl)f[len][p]=ret;
	return ret;
}
inline bool check(char *s){
	int p=1;
	for(int i=1;i<=m;i++){
		p=ch[p][s[i]-'0'];
		if(tg[p])return 1;
	} 
	return 0;
}
char s[N],sa[52],sb[52];
int main(){
	scanf("%s%s%s",s+1,sa+1,sb+1);
	n=strlen(s+1);m=strlen(sa+1)>>1;
	for(int i=1,p,c;i+m-1<=n;i++){
		p=1;
		for(int j=0;j<m;j++){
			c=s[i+j]-'0';
			if(!ch[p][c])ch[p][c]=++tot;
			p=ch[p][c];
		}
		tg[p]=1;
	}
	getfail();
	m=strlen(sa+1);
	memset(f,-1,sizeof(f));
	pw10[0]=1;
	for(int i=1;i<=m;i++)pw10[i]=(ll)pw10[i-1]*10%mod;
//	cerr<<solve(sa,1,1,1)+check(sa)<<"\n";
	cout<<(solve(sb,1,1,1)-solve(sa,1,1,1)+check(sa)+mod)%mod<<"\n";
	return (0-0);
}
/*
8951675223927155592759982402444004111663484015769374476127117887584934467757214664482684650548798755
114243
233232
*/