#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int o=1<<12,inf=1e9;
int n,c,w[o],ch[o][12],fail[o],cnt,d[12],e[12][12],f[o][o],lstp[o][o],lstu[o][o],ans;char s[o];queue<int> q;
void dfs(int nw,int fa,int u){
	if(!ch[u][nw]) ch[u][nw]=++cnt;
	for(int i=0;i<13;++i)
		if(i==12) w[ch[u][nw]]+=c;
		else if(e[nw][i]&&i-fa){dfs(i,nw,ch[u][nw]);break;}
}
int main(){
	scanf("%d",&n);
	for(int i=1,len,flg;i<=n;++i){
		scanf("%d%s",&c,s+1);len=strlen(s+1);flg=1;
		for(int j=0;j<12;++j) d[j]=0;
		for(int j=0;j<12;++j) for(int k=0;k<12;++k) e[j][k]=0;
		for(int j=1;j<=len;++j) s[j]-='a';
		for(int j=1;j<len;++j) e[s[j]][s[j+1]]=e[s[j+1]][s[j]]=1;
		for(int j=0;j<12;++j) for(int k=0;k<12;++k) d[j]+=e[j][k];
		for(int j=0;j<12;++j) if(d[j]>2){flg=0;break;}
		if(flg) for(int j=0;j<12;++j) if(d[j]==1) dfs(j,-1,0);
	}
	for(int i=0;i<12;++i) if(ch[0][i]) q.push(ch[0][i]);
	for(;!q.empty();q.pop()) for(int i=0,u=q.front();i<12;++i)
		if(ch[u][i]) w[ch[u][i]]+=w[fail[ch[u][i]]=ch[fail[u]][i]],q.push(ch[u][i]);
		else ch[u][i]=ch[fail[u]][i];
	for(int i=0;i<(1<<12);++i) for(int j=0;j<=cnt;++j) f[i][j]=-inf;
	f[0][0]=0;
	for(int i=0;i<(1<<12);++i) for(int j=0;j<=cnt;++j) if(f[i][j]>=0)
		for(int k=0;k<12;++k) if(!((i>>k)&1)&&f[i][j]+w[ch[j][k]]>f[i|(1<<k)][ch[j][k]])
			f[i|(1<<k)][ch[j][k]]=f[i][j]+w[ch[j][k]],lstp[i|(1<<k)][ch[j][k]]=k,lstu[i|(1<<k)][ch[j][k]]=j;
	for(int i=0;i<=cnt;++i) if(f[(1<<12)-1][i]>ans) ans=f[(1<<12)-1][i];
	for(int i=0;i<=cnt;++i) if(f[(1<<12)-1][i]==ans){
		for(int j=(1<<12)-1,u=i,p;j;) putchar(97+(p=lstp[j][u])),u=lstu[j][u],j^=(1<<p);
		break;
	}
	return 0;
}