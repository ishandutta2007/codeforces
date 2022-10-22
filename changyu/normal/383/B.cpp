#include<cstdio>
#include<algorithm>
const int N=100001;
struct point{int x,y;}a[N];
bool Cmp(const point&a,const point&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int n,d,l[2][N],r[2][N],k[2],t,yy[N];
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=d;i++)scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(1+a,1+a+d,Cmp);
	k[0]=1;l[0][1]=1,r[0][1]=2;t=0;
	int lst=0;
	for(int i=1;i<=d;i++){
	  yy[++t]=a[i].y;
	  if(i<d&&a[i].x==a[i+1].x)continue;
	  yy[++t]=n+1;
	  if(a[i].x-lst>1)
		k[0]=1,r[0][1]=n;
	  for(int j=1,p=1;j<=k[0];j++){
		for(;yy[p-1]<r[0][j]&&p<=t;p++){
		  l[1][++k[1]]=std::max(yy[p-1]+1,l[0][j]),
		  r[1][k[1]]=yy[p]-1;
		  if(l[1][k[1]]>r[1][k[1]])k[1]--;
		}if(p-1)p--;
	  }
	  lst=a[i].x;t=0;
	  k[0]=k[1],k[1]=0;
	  for(int j=1;j<=k[0];j++)
		l[0][j]=l[1][j],r[0][j]=r[1][j];
	  if(!k[0])break;
	}
	if(!k[0])return puts("-1"),0;
	if(lst==n&&r[0][k[0]]!=n)return puts("-1"),0;
	printf("%d\n",n+n-2);
	return 0;
}