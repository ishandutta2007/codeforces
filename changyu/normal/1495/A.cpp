#include<bits/stdc++.h>
const int N=1e5+3;
int n,a[N],b[N],k,l;double s;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	s=0;
	scanf("%d",&n);
	k=l=0;
	for(int i=1,x,y;i<=n+n;i++){
	  scanf("%d%d",&x,&y),x=std::abs(x),y=std::abs(y);
	  if(!y)a[++k]=x;if(!x)b[++l]=y;
	}
	std::sort(a+1,a+1+n),std::sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)s+=sqrt((long long)a[i]*a[i]+(long long)b[i]*b[i]);
	printf("%.12lf\n",s);
	}return 0;
}