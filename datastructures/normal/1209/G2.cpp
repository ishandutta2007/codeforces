#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,q,a[200005],x,y;
set<int> c[200005];
int l[200005],r[200005],cnt[200005];
int qwq[200005];
int mx[1000005],cov[1000005],fir[1000005],lst[1000005],firmx[1000005],lstmx[1000005],val[1000005];
void pushup(int now,int nowl,int nowr){
	int mid=(nowl+nowr)/2;
	mx[now]=max(mx[now*2],mx[now*2+1]);
	if (cov[now]==0){
		if (fir[now*2]==mid){
			fir[now]=fir[now*2+1];
			firmx[now]=max(val[now*2],firmx[now*2+1]);
		}
		else{
			fir[now]=fir[now*2];
			firmx[now]=firmx[now*2];
		}
		if (lst[now*2+1]==mid){
			lst[now]=lst[now*2];
			lstmx[now]=max(val[now*2+1],lstmx[now*2]);
		}
		else{
			lst[now]=lst[now*2+1];
			lstmx[now]=lstmx[now*2+1];
		}
		val[now]=val[now*2]+val[now*2+1]-lstmx[now*2]-firmx[now*2+1]+max(lstmx[now*2],firmx[now*2+1]);
	}
	else{
		fir[now]=nowr,lst[now]=nowl;
		firmx[now]=lstmx[now]=mx[now];
		val[now]=mx[now];
	}
	return;
}
void build(int now,int nowl,int nowr){
	fir[now]=nowl,lst[now]=nowr;
	if (nowr-nowl==1)return;
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid,nowr);
	return;
}
void upd1(int now,int nowl,int nowr,int pos){
	if (nowr-nowl==1){
		mx[now]=max(qwq[nowl],qwq[nowr]);
		if (cov[now]==0){
			fir[now]=nowl,lst[now]=nowr;
			firmx[now]=qwq[nowl],lstmx[now]=qwq[nowr];
			val[now]=qwq[nowl]+qwq[nowr];
		}
		else{
			fir[now]=nowr,lst[now]=nowl;
			firmx[now]=lstmx[now]=mx[now];
			val[now]=max(qwq[nowl],qwq[nowr]);
		}
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)upd1(now*2,nowl,mid,pos);
	if (pos>=mid)upd1(now*2+1,mid,nowr,pos);
	pushup(now,nowl,nowr);
	return;
}
void upd2(int now,int nowl,int nowr,int lt,int rt,int d){
	if (nowl>=lt&&nowr<=rt){
		cov[now]+=d;
		if (nowr-nowl==1){
			if (cov[now]==0){
				fir[now]=nowl,lst[now]=nowr;
				firmx[now]=qwq[nowl],lstmx[now]=qwq[nowr];
				val[now]=qwq[nowl]+qwq[nowr];
			}
			else{
				fir[now]=nowr,lst[now]=nowl;
				firmx[now]=lstmx[now]=mx[now];
				val[now]=max(qwq[nowl],qwq[nowr]);
			}
		}
		else pushup(now,nowl,nowr);
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>lt)upd2(now*2,nowl,mid,lt,rt,d);
	if (mid<rt)upd2(now*2+1,mid,nowr,lt,rt,d);
	pushup(now,nowl,nowr);
	return;
}
int main(){
	n=read(),q=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		c[a[i]].insert(i);
		cnt[a[i]]++;
		if (l[a[i]]==0)l[a[i]]=i;
		r[a[i]]=i;
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)
		if (l[i]!=0&&r[i]!=0){
			qwq[r[i]]=cnt[i];
			upd1(1,1,n,r[i]);
			if (l[i]<r[i])upd2(1,1,n,l[i],r[i],1);
		}
	printf("%d\n",n-val[1]);
	while(q--){
		x=read(),y=read();
		cnt[a[x]]--;
		qwq[r[a[x]]]=0;
		upd1(1,1,n,r[a[x]]);
		if (l[a[x]]<r[a[x]])upd2(1,1,n,l[a[x]],r[a[x]],-1);
		c[a[x]].erase(x);
		if (c[a[x]].begin()==c[a[x]].end())l[a[x]]=r[a[x]]=0;
		else{
			set<int>::iterator it=c[a[x]].begin();
			l[a[x]]=(*it);
			it=c[a[x]].end();
			it--;
			r[a[x]]=(*it);
		}
		if (l[a[x]]!=0&&r[a[x]]!=0){
			qwq[r[a[x]]]=cnt[a[x]];
			upd1(1,1,n,r[a[x]]);
			if (l[a[x]]<r[a[x]])upd2(1,1,n,l[a[x]],r[a[x]],1);
		}
		a[x]=y;
		cnt[a[x]]++;
		if (l[a[x]]!=0&&r[a[x]]!=0){
			qwq[r[a[x]]]=0;
			upd1(1,1,n,r[a[x]]);
			if (l[a[x]]<r[a[x]])upd2(1,1,n,l[a[x]],r[a[x]],-1);
		}
		c[a[x]].insert(x);
		if (c[a[x]].begin()==c[a[x]].end())l[a[x]]=r[a[x]]=0;
		else{
			set<int>::iterator it=c[a[x]].begin();
			l[a[x]]=(*it);
			it=c[a[x]].end();
			it--;
			r[a[x]]=(*it);
		}
		qwq[r[a[x]]]=cnt[a[x]];
		upd1(1,1,n,r[a[x]]);
		if (l[a[x]]<r[a[x]])upd2(1,1,n,l[a[x]],r[a[x]],1);
		printf("%d\n",n-val[1]);
	}
	return 0;
}