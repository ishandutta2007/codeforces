#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int n,a[N],block,shu[N],m,k,x,y,d,ans,p1,p2,s1,s2,now;
struct node{
	int num[N],a[1000],l,r,s;
}b[2][318];
void find(int x){
	s2=0;
	for(int i=1;i<=shu[n];i++){
		if(s2+b[now][i].s>=x){
			p2=i;return;
		}
		else s2+=b[now][i].s;
	}
}
void change2(int x,int y,int z){
	int xx=z-y;
	d=b[now][x].a[xx];
	b[now][x].num[d]--;
	for(int i=xx;i<b[now][x].s;i++)b[now][x].a[i]=b[now][x].a[i+1];
	b[now][x].s--;
}
void change1(int x,int y,int z){
	int xx=z-y;
	b[now][x].s++;
	for(int i=b[now][x].s;i>xx;i--)b[now][x].a[i]=b[now][x].a[i-1];
	b[now][x].a[xx]=d;
	b[now][x].num[d]++;
}
void rebuild(){
	int np=1;int ns=0;
	for(int i=1;i<=shu[n];i++)for(int j=1;j<=b[now^1][i].s;j++){
		b[now^1][i].num[b[now^1][i].a[j]]--;
	}
	for(int i=1;i<=shu[n];i++)b[now^1][i].s=b[0][i].r-b[0][i].l+1;
	for(int i=1;i<=shu[n];i++){
		for(int j=1;j<=b[now][i].s;j++){
			b[now^1][np].a[++ns]=b[now][i].a[j];
			b[now^1][np].num[b[now][i].a[j]]++;
			if(ns>=b[now^1][np].s)np++,ns=0;
		}
	}
	now^=1;
}
int main(){
	scanf("%d",&n);block=sqrt(n);now=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)shu[i]=(i-1)/block+1;
	for(int i=1;i<=shu[n];i++)b[now][i].l=(i-1)*block+1,b[now][i].r=i*block;
	b[now][shu[n]].r=n;
	for(int i=1;i<=shu[n];i++)b[now][i].s=b[now][i].r-b[now][i].l+1;
	for(int i=1;i<=n;i++){
		b[now][shu[i]].a[i-b[now][shu[i]].l+1]=a[i];b[now][shu[i]].num[a[i]]++;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&k,&x,&y);
		x=(x+ans-1)%n+1;y=(y+ans-1)%n+1;
		if(x>y)swap(x,y);
		if(k==1){
			find(x);p1=p2;s1=s2;
			find(y);
			change2(p2,s2,y);
			change1(p1,s1,x);
			if(b[now][p1].s>2*sqrt(n))rebuild();
		}
		else{
			scanf("%d",&d);
			d=(d+ans-1)%n+1;ans=0;
			find(x);p1=p2;s1=s2;
			find(y);
			for(int i=p1+1;i<p2;i++)ans+=b[now][i].num[d];
			if(p1==p2){
				for(int i=x-s1;i<=y-s1;i++)if(b[now][p1].a[i]==d)ans++;
			}
			else{
				for(int i=x-s1;i<=b[now][p1].s;i++)if(b[now][p1].a[i]==d)ans++;
				for(int i=1;i<=y-s2;i++)if(b[now][p2].a[i]==d)ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}