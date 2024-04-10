#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}A[200002];
bool cmp(node x,node y){
	return x.a<y.a;
}
int s[200002];
int main(){
	int t,n,x,y,j,i;
	long long ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x,&y,&n);
		for(i=1;i<=n;++i)scanf("%d",&A[i].a);
		for(i=1;i<=n;++i)scanf("%d",&A[i].b);
		sort(A+1,A+1+n,cmp);
		for(i=1;i<=y;++i)s[i]=0;
		ans=0;
		for(i=1;i<=n;i=j){
			for(j=i;j<=n&&A[j].a==A[i].a;++j){
				ans+=1LL*(i-1-s[A[j].b]);
				++s[A[j].b];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}