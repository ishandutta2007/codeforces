#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=1004;
const int maxm=55;

char s[maxn];
int srt[maxn];
char l[maxm],r[maxm];
int n,m;

struct node{
	int g[10],fa,fg[10],len;
};

node p[maxn*4];int ps;
int rt;
int append(int s,int ch){
	int sc=++ps;
	p[sc].len=p[s].len+1;
	for(;s!=rt&&!p[s].g[ch];s=p[s].fa)p[s].g[ch]=sc;
	if(!p[s].g[ch]){
		p[sc].fa=rt;
		p[s].g[ch]=sc;
		return sc;
	}
	int x=p[s].g[ch];
	if(p[x].len==p[s].len+1){
		p[sc].fa=x;
	}else{
		int y=++ps;
		p[y].len=p[s].len+1;
		p[y].fa=p[x].fa;
		for(int i=0;i<10;i++)p[y].g[i]=p[x].g[i];
		p[x].fa=y;
		p[sc].fa=y;
		for(;p[s].g[ch]==x;s=p[s].fa)p[s].g[ch]=y;
	}
	return sc;
}

const int mdn=1000000007;

int mem[maxm][maxn*2][maxm][2][2];
int dfs(int pos,int x,int d,bool d1,bool d2){
	if(pos>m)return 1;
	if(mem[pos][x][d][d1][d2]!=-1)return mem[pos][x][d][d1][d2];
	int lb=d1?(l[pos]-'0'):0;
	int rb=d2?(r[pos]-'0'):9;
	int ans=0;
	for(int i=lb;i<=rb;i++){
		//cerr<<x<<','<<d<<"  +"<<i<<"->";
		int c=p[x].fg[i],cd=min(d,p[c].len);
		if(p[c].g[i])c=p[c].g[i],cd++;
		//cerr<<c<<' '<<cd<<"\n";
		if(cd<m/2){
			ans+=dfs(pos+1,c,cd,d1&(i==lb),d2&(i==rb));
			ans-=(ans>=mdn?mdn:0);
		}
	}
	return mem[pos][x][d][d1][d2]=ans;
}

int gf(int u,int x){
	if(p[u].fg[x])return p[u].fg[x];
	if(p[u].g[x])return p[u].fg[x]=u;
	if(u==rt)return p[u].fg[x]=u;
	else return p[u].fg[x]=gf(p[u].fa,x);
}
int main(){
	scanf("%s%s%s",s+1,l+1,r+1);
	n=strlen(s+1);m=strlen(l+1);
	rt=++ps;p[rt].fa=rt;p[rt].len=0;
	srt[0]=rt;
	for(int i=1;i<=n;i++)srt[i]=append(srt[i-1],s[i]-'0');
	for(int i=1;i<=ps;i++)for(int j=0;j<10;j++)gf(i,j);
	memset(mem,-1,sizeof(mem));
	int res=dfs(1,rt,0,1,1);
	int w=0;
	for(int i=1;i<=m;i++)w=(w*10ll+(r[i]-'0')-(l[i]-'0')+mdn)%mdn;
	cout<<(w+1+mdn-res)%mdn;
	return 0;
}