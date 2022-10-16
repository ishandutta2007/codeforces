#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[1000005],f[1000005],tot,sta[1000005][3];
int q[1000005],head,tail;
int val[1000005];
void bfs(int n){
	memset(f,-1,sizeof(f));
	memset(val,0x7f,sizeof(val));
	head=tail=1;
	q[1]=0;
	f[0]=0;
	int mxd=0;
	while(head<=tail){
		int now=q[head];
		head++;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				for (int k=j+1;k<n;k++)
					if (j-i==k-j){
						int nxt=(now^(1<<i)^(1<<j)^(1<<k));
						if (f[nxt]==-1){
							f[nxt]=f[now]+1;
							q[++tail]=nxt;
						}
					}
		val[now>>3]=min(val[now>>3],f[now]);
	}
	int mxval=0;
	for (int i=0;i<(1<<n)>>3;i++)
		mxval=max(mxval,val[i]);
	return;
}
void dfs1(int now,int n,int l){
	if ((now>>3)==0)return;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			for (int k=j+1;k<n;k++)
				if (j-i==k-j){
					int nxt=(now^(1<<i)^(1<<j)^(1<<k));
					if (val[nxt>>3]==val[now>>3]-1){
						++tot;
						sta[tot][0]=l+i,sta[tot][1]=l+j,sta[tot][2]=l+k;
						a[l+i]^=1,a[l+j]^=1,a[l+k]^=1;
						dfs1(nxt,n,l);
						return;
					}
				}
	return;
}
void dfs2(int now,int n,int l){
	if (now==0)return;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			for (int k=j+1;k<n;k++)
				if (j-i==k-j){
					int nxt=(now^(1<<i)^(1<<j)^(1<<k));
					if (f[nxt]==f[now]-1){
						++tot;
						sta[tot][0]=l+i,sta[tot][1]=l+j,sta[tot][2]=l+k;
						a[l+i]^=1,a[l+j]^=1,a[l+k]^=1;
						dfs2(nxt,n,l);
						return;
					}
				}
	return;
}
int getval(int l,int r){
	int val=0;
	for (int i=r;i>=l;i--)val=val*2+a[i];
	return val;
}
void out(){
	puts("YES");
	cout<<tot<<endl;
	for (int i=1;i<=tot;i++)printf("%d %d %d\n",sta[i][0],sta[i][1],sta[i][2]);
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	bfs(12);
	int pos=n;
	while(pos>18){
		dfs1(getval(pos-11,pos),12,pos-11);
		pos-=9;
	}
	bfs(pos);
	int qwq=getval(1,pos);
	if (f[qwq]==-1)puts("NO");
	else dfs2(qwq,pos,1),out();
	return 0;
}