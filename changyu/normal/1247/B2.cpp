#include<cstdio>
const int N=2e5+3,A=1e6+3;
int n,k,d,a[N],b[A],c,ans;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%d",&n,&k,&d);
	ans=n;c=0;
	for(int i=1;i<=n;i++){
	  scanf("%d",a+i);
	  if(!b[a[i]])c++;
	  b[a[i]]++;
	  if(i>d){
		b[a[i-d]]--;
		if(!b[a[i-d]])c--;
	  }
	  if(i>=d)ans=c<ans?c:ans;
	}
	for(int i=1;i<=n;i++)b[a[i]]=0;
	printf("%d\n",ans);
	}return 0;
}