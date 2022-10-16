#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define inf 1000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct BIT{
	int tree[1000005],maxn;
	BIT(){
		memset(tree,0x7f,sizeof(tree));
		maxn=1000000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]=min(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=inf;
		while(pos)ans=min(ans,tree[pos]),pos-=lowbit(pos);
		return ans;
	}
}bit;
int n,q,a[2000005];
int pos[9][6000005],qwq[20];
int isp[6000005],tot,p[1000005],c[6000005];
vector<int> qr[2000005],qid[2000005];
int ans[2000005];
void pre_work(int maxn){
	isp[0]=isp[1]=1;
	c[0]=-1,c[1]=0;
	for (int i=2;i<=maxn;i++){
		if (isp[i]==1)continue;
		p[++tot]=i,c[i]=1;
		for (int j=2*i;j<=maxn;j+=i)isp[j]=1,c[j]=c[j/i]+1;
	}
	return;
}
int main(){
	cin>>n>>q;
	pre_work(6000000);
	for (int i=1;i<=n;i++){
		a[i]=read();
		int qwq=1;
		for (int j=1;p[j]*p[j]<=a[i];j++){
			if (a[i]%p[j]!=0)continue;
			int cnt=0;
			while(a[i]%p[j]==0)a[i]/=p[j],cnt++;
			if (cnt&1)qwq*=p[j];
		}
		a[i]*=qwq;
	}
	for (int i=1;i<=q;i++){
		int l=read(),r=read();
		qr[l].push_back(r);
		qid[l].push_back(i);
	}
	memset(pos,0x7f,sizeof(pos));
	for (int i=n;i>=1;i--){
		memset(qwq,0x7f,sizeof(qwq));
		for (int j=1;j*j<=a[i];j++){
			if (a[i]%j!=0)continue;
			for (int k=0;k<=8;k++){
				if (c[a[i]]+k-2*c[j]>=0)qwq[c[a[i]]+k-2*c[j]]=min(qwq[c[a[i]]+k-2*c[j]],pos[k][j]);
				if (c[a[i]]+k-2*c[a[i]/j]>=0)qwq[c[a[i]]+k-2*c[a[i]/j]]=min(qwq[c[a[i]]+k-2*c[a[i]/j]],pos[k][a[i]/j]);
			}
		}
		for (int j=1;j*j<=a[i];j++){
			if (a[i]%j!=0)continue;
			pos[c[a[i]]][j]=i;
			pos[c[a[i]]][a[i]/j]=i;
		}
		for (int j=0;j<20;j++)
			if (qwq[j]<=n)bit.add(qwq[j],j);
		for (int j=0;j<(int)qr[i].size();j++)ans[qid[i][j]]=bit.ask(qr[i][j]);
	}
	for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}