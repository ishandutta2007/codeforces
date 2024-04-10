#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5;
int n,m;
int a[N],b[N],ca,cb;
int main(){
	int i,j;
	int _;scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ca=cb=0;
		for(i=1;i<=2*n;i++){
			int x,y;scanf("%d%d",&x,&y);
			if(x==0) b[++cb]=((y<0)?-y:y);
			else a[++ca]=((x<0)?-x:x);
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		double ans=0;
		for(i=1;i<=n;i++)
			ans+=sqrtl((double)a[i]*a[i]+(double)b[i]*b[i]);
		printf("%.15lf\n",ans);
	}
	return 0;
}