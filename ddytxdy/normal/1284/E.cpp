#include<bits/stdc++.h>
#define LL long long
#define ld long double
using namespace std;
const int N=3000,M=3e7+50;
int n,f[N][N];LL ans,dat;
struct poi{
	int x,y;ld dat;
	bool friend operator <(poi a,poi b){return a.dat<b.dat;}
	LL operator *(const poi &b){
		return 1ll*x*b.y-1ll*y*b.x;
	}
}a[N],b[N];
LL C5(int x){if(x<5)return 0;return 1ll*x*(x-1)*(x-2)*(x-3)*(x-4)/120;}
LL C3(int x){if(x<3)return 0;return 1ll*x*(x-1)*(x-2)/6;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	ans=C5(n)*5;//cout<<ans<<" ";
	for(int i=1;i<=n;i++){
		for(int j=1,k=0;j<=n;j++){
			if(j==i)continue;
			b[k].x=a[j].x-a[i].x,b[k].y=a[j].y-a[i].y,
			b[k].dat=atan2(b[k].y,b[k].x);
			k++;
		}
		//dat+=(n-1)*C3(n-2);
		int m=n-1;sort(b,b+m);
		for(int j=0,k=0;j<m;j++){
			while((k+1)%m!=j&&b[j]*b[(k+1)%m]>0)k++,k%=m;
			int d=(k-j+m)%m;//cout<<d<<" ";
			dat+=C3(d);dat+=C3(m-1-d);
		}
	}
	cout<<ans-dat/2;
	return 0;
}