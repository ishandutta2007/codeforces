#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50;
int t,n,a,b,c,x[N],p,p2,p3,mx;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);p=0;mx=0;
		for(int i=1;i<=n;i++)scanf("%d",&x[i]);
		while(p<n&&x[p+1]==x[1])p++;
		if(p==n){puts("0 0 0");continue;}p2=p+1;int la=x[p2];
		while(p2<n&&(x[p2+1]==la||p2-p<=p))p2++,la=x[p2];
		if(p2*2>=n){puts("0 0 0");continue;}p3=p2;
		while(1){
			p3++;int la=x[p3];
			while(p3<n&&(x[p3+1]==la||p3-p2<=p))p3++,la=x[p3];
			if(p3*2<=n)mx=p3;else break;
		}
		if(mx)printf("%d %d %d\n",p,p2-p,mx-p2);
		else puts("0 0 0");
	}
	return 0;
}