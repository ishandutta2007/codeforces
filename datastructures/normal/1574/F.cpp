#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define int long long
#define mod 998244353
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,k,len[1000005];
vector<int> c[1000005],d[1000005];
int dsu[1000005],dsu_pos[1000005];
int pre[1000005],nxt[1000005];
int chk;
int trans_num,trans[1000005],cnt[1000005],num_1;
int f[1000005];
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
void dsu_merge(int x,int y){
	x=dsu_find(x),y=dsu_find(y);
	if (x==y)return;
	dsu[x]=y;
	return;
}
int id[1000005],book[1000005];
int deg_in[1000005],deg_out[1000005];
int work(int awa){
	int num=0,tot=d[awa].size();
	for (int i=1;i<=tot;i++)id[i]=d[awa][i-1];
	for (int i=1;i<=tot;i++)
		for (int j=0;j<len[id[i]];j++){
			int now=c[id[i]][j];
			book[now]++;
			if (book[now]==1)num++;
		}
	for (int i=1;i<=tot;i++)
		for (int j=0;j<len[id[i]];j++){
			int now=c[id[i]][j];
			book[now]=0;
		}
	for (int i=1;i<=tot;i++){
		for (int j=0;j<len[id[i]];j++){
			int now=c[id[i]][j];
			if (book[now]==1)chk=0;
			book[now]=1;
		}
		for (int j=0;j<len[id[i]];j++){
			int now=c[id[i]][j];
			book[now]=0;
		}
	}
	for (int i=1;i<=tot;i++)
		for (int j=1;j<len[id[i]];j++){
			if (pre[c[id[i]][j]]!=0&&pre[c[id[i]][j]]!=c[id[i]][j-1])chk=0;
			else if (pre[c[id[i]][j]]==0)pre[c[id[i]][j]]=c[id[i]][j-1],deg_in[c[id[i]][j]]++;
		}
	for (int i=1;i<=tot;i++)
		for (int j=0;j<len[id[i]]-1;j++){
			if (nxt[c[id[i]][j]]!=0&&nxt[c[id[i]][j]]!=c[id[i]][j+1])chk=0;
			else if (nxt[c[id[i]][j]]==0)nxt[c[id[i]][j]]=c[id[i]][j+1],deg_out[c[id[i]][j]]++;
		}
	int qaq=0;
	for (int i=1;i<=tot;i++)
		for (int j=0;j<len[id[i]];j++){
			int now=c[id[i]][j];
			if (deg_in[now]>1||deg_out[now]>1)chk=0;
			if (deg_in[now]==0||deg_out[now]==0)qaq=1;
		}
	if (qaq==0)chk=0;
	for (int i=1;i<=tot;i++)
		for (int j=0;j<len[id[i]];j++){
			int now=c[id[i]][j];
			book[now]=pre[now]=nxt[now]=deg_in[now]=deg_out[now]=0;
		}
	return num;
}
signed main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)dsu[i]=i;
	for (int i=1;i<=n;i++){
		len[i]=read();
		for (int j=1;j<=len[i];j++){
			int x=read();
			c[i].push_back(x);
			if (dsu_pos[x]==0)dsu_pos[x]=i;
			else dsu_merge(i,dsu_pos[x]);
		}
	}
	for (int i=1;i<=n;i++)d[dsu_find(i)].push_back(i);
	num_1=k;
	for (int i=1;i<=n;i++)
		if (i==dsu_find(i)){
			chk=1;
			int val=work(i);
			num_1-=val;
			if (chk==0)continue;
			cnt[val]++;
			if (cnt[val]==1)trans[++trans_num]=val;
		}
	f[0]=1;
	for (int i=1;i<=m;i++){
		f[i]=f[i-1]*num_1%mod;
		for (int j=1;j<=trans_num;j++)
			if (trans[j]<=i)f[i]=(f[i]+f[i-trans[j]]*cnt[trans[j]])%mod;
	}
	cout<<f[m]<<endl;
	return 0;
}