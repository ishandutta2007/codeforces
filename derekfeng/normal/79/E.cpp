#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
int n,a,b,c;
int x[4],y[4];
ll num[4];
ll calc(int l,int r){
	return (ll)(l+r)*(r-l+1)/2;
}
bool check1(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	for(int i=0;i<4;i++)
		pnum[i]-=calc(px-x[i]+py-y[i],n-x[i]+n-y[i]);
	for(int i=0;i<4;i++)if(pnum[i]<0)return 0;
	return 1;
}
bool check2(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	for(int i=0;i<2;i++)pnum[i]-=calc(px-x[i]+py-y[i],px-x[i]+y[3]-y[i]);
	for(int i=2;i<4;i++)pnum[i]-=calc(px-x[i],px-x[i]+y[i]-py);
	py=y[3];
	for(int i=0;i<4;i++)pnum[i]+=abs(x[i]-px)+abs(y[i]-py);
	return check1(px,py,pnum);
}
bool check3(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	for(int i=0;i<4;i+=2)pnum[i]-=calc(px-x[i]+py-y[i],x[3]-x[i]+py-y[i]);
	for(int i=1;i<4;i+=2)pnum[i]-=calc(py-y[i],py-y[i]+x[i]-px);
	px=x[3];
	for(int i=0;i<4;i++)pnum[i]+=abs(x[i]-px)+abs(y[i]-py);
	return check1(px,py,pnum);
}
bool check4(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	for(int i=0;i<4;i++)pnum[i]-=calc(px-x[i]+y[i]-y[0],px-x[i]+y[i]-py);
	py=y[0];
	for(int i=0;i<4;i++)pnum[i]+=abs(x[i]-px)+abs(y[i]-py);
	return check2(px,py,pnum);
}
bool check5(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	for(int i=0;i<4;i++)pnum[i]-=calc(x[i]-x[0]+py-y[i],x[i]-px+py-y[i]);
	px=x[0];
	for(int i=0;i<4;i++)pnum[i]+=abs(x[i]-px)+abs(y[i]-py);
	return check2(px,py,pnum);
}
bool check6(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	if(x[3]<n||y[3]<n){
		for(int i=0;i<4;i++)pnum[i]-=calc(x[3]-x[i]+y[3]-y[i],n-x[i]+n-y[i]);
		for(int i=0;i<4;i++)pnum[i]+=abs(x[3]-x[i])+abs(y[3]-y[i]);
	}
	pnum[0]-=calc(px-x[0]+py-y[0],x[3]-x[0]+y[3]-y[0]);
	pnum[3]-=calc(0,x[3]-px+y[3]-py);
	if(pnum[0]<0||pnum[3]<0)return 0;
	ll SUM=(ll)(x[3]+y[3]-px-py+1)*(2*c-2);
	ll L=calc(px-x[2],px-x[2]+y[2]-py)+calc(px-x[2],x[3]-x[2])-(px-x[2]);
	ll LL=calc(py-y[1],x[1]-px+py-y[1])+calc(py-y[1],y[3]-y[1])-(py-y[1]);
	ll R=SUM-LL;
	if(pnum[2]-R<0){
		R=pnum[2];
		if((R&1)!=(L&1))R--;
	}
	if(R<L)return 0;
	return pnum[1]-(SUM-R)>=0;
}
bool check7(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	for(int i=0;i<4;i++)pnum[i]-=calc(abs(x[i]-px)+y[i]-y[0],abs(x[i]-px)+y[i]-py);
	py=y[0];
	for(int i=0;i<4;i++)pnum[i]+=abs(x[i]-px)+abs(y[i]-py);
	return check6(px,py,pnum);
}
bool check8(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	for(int i=0;i<4;i++)pnum[i]-=calc(x[i]-x[0]+abs(y[i]-py),x[i]-px-abs(y[i]-py));
	px=x[0];
	for(int i=0;i<4;i++)pnum[i]+=abs(x[i]-px)+abs(y[i]-py);
	return check6(px,py,pnum);
}
bool check9(int px,int py,ll num[4]){
	ll pnum[4];
	memcpy(pnum,num,sizeof(pnum));
	for(int i=0;i<4;i++)pnum[i]-=calc(x[i]-x[0]+y[i]-y[0],x[i]-px+y[i]-py);
	px=x[0],py=y[0];
	for(int i=0;i<4;i++)pnum[i]+=abs(x[i]-px)+abs(y[i]-py);
	return check6(px,py,pnum);
}
bool check(int px,int py,ll num[4]){
	if(px>=x[3]&&py>=y[3])return check1(px,py,num);
	if(px>=x[3]&&py>=y[0])return check2(px,py,num);
	if(px>=x[0]&&py>=y[3])return check3(px,py,num);
	if(px>=x[3])return check4(px,py,num);
	if(py>=y[3])return check5(px,py,num);
	if(px>=x[0]&&py>=y[0])return check6(px,py,num);
	if(px>=x[0])return check7(px,py,num);
	if(py>=y[0])return check8(px,py,num);
	return check9(px,py,num);
}
int main(){
	scanf("%d%lld%d%d%d",&n,&T,&a,&b,&c);
	x[0]=a,y[0]=b;
	x[1]=a+c-1,y[1]=b;
	x[2]=a,y[2]=b+c-1;
	x[3]=a+c-1,y[3]=b+c-1;
	for(int i=0;i<4;i++)num[i]=T+abs(x[i]-1)+abs(y[i]-1);
	if(!check(1,1,num))return puts("Impossible"),0;
	for(int i=0;i<4;i++)num[i]-=abs(x[i]-1)+abs(y[i]-1);
	int px=1,py=1;
	while(px!=n||py!=n){
		if(px!=n&&check(px+1,py,num))px++,putchar('R');
		else py++,putchar('U');
		for(int i=0;i<4;i++)num[i]-=abs(x[i]-px)+abs(y[i]-py);
	}
}