#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,Q,q[N*2],mx,la,ans1[N],ans2[N],l,r;LL x;
int main(){
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]),mx=max(mx,q[i]);
	l=1;r=n;
	while(q[l]!=mx){
		int x=q[l],y=q[l+1];
		ans1[++la]=x,ans2[la]=y;
		l++;q[l]=max(x,y);q[++r]=min(x,y);
	}
	for(int i=1;i<=Q;i++){
		cin>>x;
		if(x<=la)printf("%d %d\n",ans1[x],ans2[x]);
		else{
			x=(x-la)%(n-1);if(!x)x=n-1;
			printf("%d %d\n",mx,q[l+x]);
		}
	}
	return 0;
}