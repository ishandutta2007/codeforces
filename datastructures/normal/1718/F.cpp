#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#define maxn 100000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct BIT{
	int tree[100005];
	BIT(){
		memset(tree,0,sizeof(tree));
		return;
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=(pos&(-pos));
		return; 
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=(pos&(-pos));
		return ans;
	}
}bit[325];
int n,m,C,q,a[100005];
vector<int> qr[100005],qid[100005];
int ans[100005];
bool isp(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}
int tot,p[100005],id[100005];
int f[65536];
int occ[100005];
bitset<1700> t[17],d;
int qwq[505],awa[505],cnt[505];
int sum[1700];
int work(){
	int ans=0;
	int s=0;
	for (int i=1;i<=16;i++)
		if (qwq[i]==1)s|=(1<<(i-1));
	ans+=f[s];
	for (int i=1;i<1700;i++){
		sum[i]=sum[i-1];
		if (d[i]==1)sum[i]++;
	}
	for (int i=1;i<=320;i++)cnt[i]=cnt[i-1]+awa[i];
	for (int i=1;i<=320;i++)ans-=awa[i]*sum[i];
	for (int i=17;i<=65;i++){
		if (qwq[i]==0)continue;
		ans-=sum[C/p[i]];
		for (int j=1;p[i]*j<=320;j++)
			ans+=(cnt[min(320,p[i]*(j+1)-1)]-cnt[min(320,p[i]*j-1)])*sum[j];
	}
	for (int i=17;i<=65;i++){
		if (qwq[i]==0)continue;
		for (int j=i+1;j<=65;j++){
			if (qwq[j]==0)continue;
			ans+=sum[C/(p[i]*p[j])];
		}
	}
	return ans;
}
int main(){
	cin>>n>>m>>C>>q;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=q;i++){
		int l,r;
		l=read(),r=read();
		qr[l].push_back(r),qid[l].push_back(i);
	}
	for (int i=2;i<=maxn;i++)
		if (isp(i))p[++tot]=i,id[i]=tot;
	for (int i=0;i<(1<<16);i++){
		int val=C,pc=0;
		for (int j=0;j<16;j++)
			if (i&(1<<j))val/=p[j+1],pc++;
		if (!(pc&1))f[i]=val;
		else f[i]=-val;
	}
	for (int i=(1<<16)-1;i>0;i--){
		for (int j=((i-1)&i);j;j=((j-1)&i))f[i]+=f[j];
		f[i]+=f[0];
	}
	for (int i=1;i<=16;i++){
		for (int j=0;j<1700;j++)
			if (j%p[i]!=0)t[i][j]=1;
			else t[i][j]=0;
	}
	for (int i=n;i>=1;i--){
		int x=a[i];
		for (int j=1;j<=65;j++){
			if (x%p[j]!=0)continue;
			occ[j]=i;
			while(x%p[j]==0)x/=p[j];
		}
		if (x>1){
			if (occ[id[x]]!=0)bit[C/x].add(occ[id[x]],-1);
			occ[id[x]]=i;
			bit[C/x].add(occ[id[x]],1);
		}
		for (int j=0;j<(int)qr[i].size();j++){
			d[0]=0;
			for (int k=1;k<1700;k++)d[k]=1;
			for (int k=1;k<=16;k++)
				if (occ[k]!=0&&occ[k]<=qr[i][j])d&=t[k];
			for (int k=1;k<=65;k++)
				if (occ[k]!=0&&occ[k]<=qr[i][j])qwq[k]=1;
				else qwq[k]=0;
			for (int k=1;k<=320;k++)awa[k]=bit[k].ask(qr[i][j]);
			ans[qid[i][j]]=work();
		}
	}
	for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}