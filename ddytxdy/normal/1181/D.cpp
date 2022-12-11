#include<bits/stdc++.h>
#define lowbit(x) x&-x
#define LL long long
using namespace std;
const int N=5e5+50;
int n,m,Q,x,s[N],y,num[N],f[N],lo,ans[N];LL ss[N];
struct node{
	int x,id;
	bool friend operator <(node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		return a.id<b.id;
	}
}a[N];
struct node1{
	LL q;int id;
	bool friend operator <(node1 a,node1 b){return a.q<b.q;}
}q[N];
void add(int x){for(;x<=m;x+=lowbit(x))f[x]++;}
int k_th(int k){
    int now=0;k--;
    for(int i=1<<lo;i;i>>=1)
        if(now+i<=m&&f[now+i]<=k)
            k-=f[now+i],now+=i;
    return now+1;
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);lo=log2(m);
	for(int i=1;i<=n;i++)scanf("%d",&x),a[x].x++;
	for(int i=1;i<=m;i++)a[i].id=i;
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)s[i]=s[i-1]+a[i].x;
	for(int i=1;i<=m;i++)ss[i]=1ll*a[i].x*i-s[i];
	for(int i=1;i<=Q;i++)cin>>q[i].q,q[i].q-=n,q[i].id=i;
	sort(q+1,q+1+Q);
	for(int i=1,now=0;i<=Q;i++){
		LL y=q[i].q;int x;  
		if(y>ss[m])x=m;
		else x=lower_bound(ss+1,ss+m+1,y)-ss,x--;
		while(now<x)add(a[++now].id);
		int z=(y-ss[now])%now;
		if(!z)z=now;
		ans[q[i].id]=k_th(z);
	}
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
	return 0;
}