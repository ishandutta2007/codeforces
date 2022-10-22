#include <bits/stdc++.h>
using namespace std;

int n,a[200010],b[200010],c[200010],p[200010],q[200010],r[200010],bit[200010];

inline int getint()
{
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	int r=0;
	while(ch>='0'&&ch<='9'){
		r=r*10+ch-'0';
		ch=getchar();
	}
	return r;
}

inline int sum(int p)
{
	int s=0;
	while(p!=0){
		s+=bit[p];
		p-=p&(-p);
	}
	return s;
}

inline void add(int p,int v)
{
	while(p<=n){
		bit[p]+=v;
		p+=p&(-p);
	}
}

inline int kth(int x)
{
	int pos=0,num=0;
	for(int i=20;i>=0;i--){
		if(pos+(1<<i)>n) continue;
		if(num+bit[pos+(1<<i)]<x){
			num+=bit[pos+(1<<i)];
			pos+=(1<<i);
		}
	}
	return pos+1;
}

signed main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=getint();
	for(int i=1;i<=n;i++) a[i]=getint(),a[i]++;
	for(int i=1;i<=n;i++) b[i]=getint(),b[i]++;
	for(int i=1;i<=n;i++) bit[i]=0;
	for(int i=1;i<=n;i++) add(a[i],1);
	for(int i=1;i<=n;i++){
		int val=sum(a[i]);
		p[n-i]=val-1;
		add(a[i],-1);
	}
	for(int i=1;i<=n;i++) bit[i]=0;
	for(int i=1;i<=n;i++) add(b[i],1);
	for(int i=1;i<=n;i++){
		int val=sum(b[i]);
		q[n-i]=val-1;
		add(b[i],-1);
	}
	for(int i=0;i<=n-1;i++){
		r[i+1]+=(r[i]+p[i]+q[i])/(i+1);
		r[i]=(r[i]+p[i]+q[i])%(i+1);
	}
	for(int i=1;i<=n;i++) bit[i]=0;
	for(int i=1;i<=n;i++) add(i,1);
	for(int i=n-1;i>=0;i--){
		c[n-i]=kth(r[i]+1);
		add(c[n-i],-1);
	}
	for(int i=1;i<=n;i++) printf("%d ",c[i]-1);
	printf("\n");
	return 0;
}