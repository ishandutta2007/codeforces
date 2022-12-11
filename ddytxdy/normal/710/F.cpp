#include<bits/stdc++.h>
using namespace std;
const int N=6e5+50;
int m,rt[2][30],sz[2][30],c[N][26],tot,cnt[N],sum[N],fail[N],q[N],l,r,num[2],c2[N][26];char s[N];
void build(int d,int x){
	int p=rt[d][x]=++tot;
	for(int i=0;s[i];i++)p=c[p][s[i]-'a']=++tot;
	cnt[p]=1;
}
void merge(int &x,int y){
	if(!x||!y){x^=y;return;}
	for(int i=0;i<26;i++)
		merge(c[x][i],c[y][i]);
	cnt[x]+=cnt[y];
}
void getfail(int rt){
	l=1;r=0;
	for(int i=0;i<26;i++)
		if(c[rt][i])fail[c2[rt][i]=q[++r]=c[rt][i]]=rt;
		else c2[rt][i]=rt;
	while(l<=r){
		int x=q[l++];sum[x]=sum[fail[x]]+cnt[x];
		for(int i=0;i<26;i++){
			int y=c[x][i],z=c2[fail[x]][i];
			if(y)fail[y]=z,c2[x][i]=q[++r]=y;
			else c2[x][i]=z;
		}
	}
}
int query(int d){
	int ret=0;
	for(int i=1;i<=num[d];i++){
		for(int j=0,p=rt[d][i];s[j];j++)
			ret+=sum[p=c2[p][s[j]-'a']];
	}
	return ret;
}
void change(int d){
	build(d,++num[d]);sz[d][num[d]]=1;
	while(num[d]>1&&sz[d][num[d]]==sz[d][num[d]-1])
		merge(rt[d][num[d]-1],rt[d][num[d]]),sz[d][--num[d]]*=2;
	getfail(rt[d][num[d]]);
}
int main(){
	scanf("%d",&m);
	for(int i=1,op;i<=m;i++){
		scanf("%d%s",&op,s);
		if(op==3)printf("%d\n",query(0)-query(1)),fflush(stdout);
		else change(op-1);
	}
	return 0;
}