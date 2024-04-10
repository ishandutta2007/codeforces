#include<cstdio>
#include<algorithm>
int x,y,a[2][2001],n[2],s;
signed main(){
	scanf("%d",&x);
	for(int i=1;i<=x;i++)scanf("%d",&y),a[y&1][++n[y&1]]=y;
	std::sort(a[0]+1,a[0]+1+n[0]);std::sort(a[1]+1,a[1]+1+n[1]);
	if(n[0]==n[1]||n[0]+1==n[1]||n[0]==n[1]+1)return 0*puts("0");
	if(n[0]>n[1])for(int i=1;i<n[0]-n[1];i++)s+=a[0][i];
	if(n[1]>n[0])for(int i=1;i<n[1]-n[0];i++)s+=a[1][i];
	printf("%d",s);
	return 0;
}