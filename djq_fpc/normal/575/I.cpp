#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,wid,cnt,i,j,ans[100005],op[100005],px[100005],py[100005],pl[100005],a[5005][5005],b[5005][10005];
int lowbit(int x)
{
	return x&(-x); 
}
void insa(int x,int y,int z)
{
	int i,j;
	for(i=x;i<=wid;i+=lowbit(i)){
		for(j=y;j<=wid;j+=lowbit(j)){
			a[i][j]+=z;
		}
	}
}
void insb(int x,int y,int z)
{
	int i,j;
	for(i=x;i<=wid;i+=lowbit(i)){
		for(j=y;j<=wid+wid;j+=lowbit(j)){
			b[i][j]+=z;
		}
	}
}
int qrya(int x,int y)
{
	int i,j,s=0;
	for(i=x;i;i-=lowbit(i)){
		for(j=y;j;j-=lowbit(j)){
			s+=a[i][j];
		}
	}
	return s;
}
int qryb(int x,int y)
{
	int i,j,s=0;
	for(i=x;i;i-=lowbit(i)){
		for(j=y;j;j-=lowbit(j)){
			s+=b[i][j];
		}
	}
	return s;
}
int main()
{
	scanf("%d%d",&wid,&n);
	fz1(i,n){
		scanf("%d",&op[i]);
		if(op[i]==2){
			op[i]=0;
			scanf("%d%d",&px[i],&py[i]);
		}
		else{
			scanf("%d",&op[i]);
			scanf("%d%d%d",&px[i],&py[i],&pl[i]);
		}
	}
	fz1(j,4){
		fz1(i,n){
			if((j-1)&2) px[i]=wid-px[i]+1;
			if((j-1)&1) py[i]=wid-py[i]+1;
		}
		
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		fz1(i,n){
			if(op[i]==j){
				insa(px[i],py[i],1);
				insa(px[i]+pl[i]+1,py[i],-1);
				insb(px[i],px[i]+py[i]+pl[i]+1,1);
				insb(px[i]+pl[i]+1,px[i]+py[i]+pl[i]+1,-1);
				/*a[px[i]][py[i]]++;
				a[px[i]+pl[i]+1][py[i]]--;
				b[px[i]][px[i]+py[i]+pl[i]+1]++;
				b[px[i]+pl[i]+1][px[i]+py[i]+pl[i]+1]--;*/
			}
			if(op[i]==0){
				ans[i]+=qrya(px[i],py[i])-qryb(px[i],px[i]+py[i]);
			}
		}
		
		fz1(i,n){
			if((j-1)&2) px[i]=wid-px[i]+1;
			if((j-1)&1) py[i]=wid-py[i]+1;
		}
	}
	
	fz1(i,n)if(op[i]==0){
		printf("%d\n",ans[i]);
	}
	return 0;
}