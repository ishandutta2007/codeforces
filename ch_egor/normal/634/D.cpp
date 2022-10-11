#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
struct data{
	int x,p;
}a[210001];
ll ans;
int lg2[210001],i,j,k,n,m,c,rmq[210001][21];
bool cmp(data x,data y){
	return x.x<y.x;
}
void rmqinit(){
	int i,j,k;
	for (lg2[1]=0,i=2;i<=n;i++) lg2[i]=((i-1)&i)?lg2[i-1]:lg2[i-1]+1;
	for (i=1;i<=n;i++) rmq[i][0]=i;
	for (i=1;(1<<i)<=n;i++)
	 for (j=1,k=(1<<(i-1));j<=n-2*k+1;j++) rmq[j][i]=(a[rmq[j][i-1]].p<=a[rmq[j+k][i-1]].p)?rmq[j][i-1]:rmq[j+k][i-1];
}
int query(int l,int r){
	int k=lg2[r-l+1];
	return (a[rmq[l][k]].p<=a[rmq[r-(1<<k)+1][k]].p)?rmq[l][k]:rmq[r-(1<<k)+1][k];
}
ll solve(int l,int r){
	int k;
	ll res;
	if (a[r].x-a[l].x<=c) return 0;
	k=query(l+1,r-1);
	if (a[k].x-a[l].x<=c) return (ll)a[k].p*(ll)(min(c,a[r].x-a[k].x)-(c-(a[k].x-a[l].x)))+solve(k,r);
	res=(ll)a[k].p*(ll)min(c,a[r].x-a[k].x)+solve(l,k)+solve(k,r);
	return res;
}
int main(){
	scanf("%d%d%d",&m,&c,&n);a[0].x=0;a[n+1].x=m;
	for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].p);
	sort(a+1,a+1+n,cmp);rmqinit();
	for (i=0;i<=n;i++)
	 if (a[i+1].x-a[i].x>c){
	 	puts("-1");return 0;
	 }
	ans=solve(0,n+1);
	cout<<ans<<endl;
	return 0;
}