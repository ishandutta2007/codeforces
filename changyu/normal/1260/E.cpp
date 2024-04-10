#include<cstdio>
#include<queue>
const int N=1<<18,INF=0x3f3f3f3f;
int n,a[N];long long ans;
std::priority_queue<int,std::vector<int>,std::greater<int> >p;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	p.push(a[n-1]);
	for(int j=n>>1,k=n-1;j;k-=j,j>>=1){
	  if(p.top()<0)break;
	  ans+=p.top(),p.pop();
	  for(int i=1;i<=j;i++)p.push(a[k-i]);
	}printf("%lld\n",ans);
	return 0;
}