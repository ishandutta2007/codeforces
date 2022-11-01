#include<bits/stdc++.h>
#define LL long long
#define db double
using namespace std;
const int N=1e5+5;
struct point{int x,y;}a[N],v[N];
bool equal(int dx,int dy,int x,int y){return (LL)dx*y==(LL)x*dy;}
int main(){
	srand(time(NULL));
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	if(n<=2){puts("YES");return 0;}
	for(int t=1,p,p2,tp;t<=1000;t++){
		p=rand()%n+1;p2=rand()%n+1;tp=0;
		if(p==p2)continue;
		if(a[p].x==a[p2].x){
			for(int i=1;i<=n;i++)if(a[i].x!=a[p].x)v[++tp]=a[i];
		}else{
			int x=a[p2].x-a[p].x,y=a[p2].y-a[p].y;
			for(int i=1;i<=n;i++)if(!equal(a[i].x-a[p].x,a[i].y-a[p].y,x,y))v[++tp]=a[i];
		}
		if(tp<=2){puts("YES");return 0;}
		bool fl=true;
		if(v[1].x==v[2].x){
			for(int i=1;i<=tp;i++)if(v[i].x!=v[1].x){fl=false;break;}	
			if(!fl)continue;else{puts("YES");return 0;}
		}else{
			int x=v[2].x-v[1].x,y=v[2].y-v[1].y;
			for(int i=1;i<=tp;i++)if(!equal(v[i].x-v[1].x,v[i].y-v[1].y,x,y)){fl=false;break;}
			if(!fl)continue;else{puts("YES");return 0;}
		}
	}
	puts("NO");
	return 0;
}