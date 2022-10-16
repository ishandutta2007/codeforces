#include <iostream>
#include <cstdio>
#include <vector> 
#include <map>
#define maxn 1000001
using namespace std;
int n,q;
int a[150005],id[1000005],fa[150005],c[1000005],qwq[1000005],s[300005],t[300005];
map<int,int> d[150005];
int fac[1005],tot;
int book[1000005],ans[300005];
int find(int x){
	if (x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if (x==y)return;
	fa[y]=x;
	return;
}
void upd(int &x,int y){
	x=min(x,y);
	return;
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),id[a[i]]=i;
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=2;i<=maxn;i++){
		if (c[i]!=0)continue;
		int fir=-1;
		for (int j=i;j<=maxn;j+=i){
			if (c[j]==0)c[j]=i;
			if (id[j]==0)continue;
			if (fir==-1)fir=id[j];
			else merge(fir,id[j]);
		}
	}
	for (int i=1;i<=q;i++)ans[i]=2;
	for (int i=1;i<=q;i++){
		scanf("%d%d",&s[i],&t[i]);
		s[i]=find(s[i]),t[i]=find(t[i]);
	}
	for (int i=1;i<=n;i++){
		int x=a[i];
		while(x>1)qwq[c[x]]=find(i),x/=c[x];
	}
	for (int i=1;i<=n;i++){
		int x=a[i];
		tot=0;
		while(x>1){
			if (c[x]!=fac[tot])fac[++tot]=c[x];
			x/=c[x];
		}
		x=a[i]+1;
		while(x>1){
			if (c[x]!=fac[tot])fac[++tot]=c[x];
			x/=c[x];
		}
		for (int j=1;j<=tot;j++)
			for (int k=1;k<j;k++)
				if (qwq[fac[j]]!=qwq[fac[k]])d[qwq[fac[j]]][qwq[fac[k]]]=1;
	}
	for (int i=1;i<=q;i++)
		if (d[s[i]][t[i]]||d[t[i]][s[i]])ans[i]=1;
	for (int i=1;i<=q;i++)
		if (s[i]==t[i])ans[i]=0;
	for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}