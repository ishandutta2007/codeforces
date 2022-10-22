#include<bits/stdc++.h>
const int N=1e5+3;
int n,mxp,mnp,mmp,x[N],y[N],z[N];
signed main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	mxp=mnp=mmp=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",x+i,y+i,z+i);
		if(mnp==0||x[i]<x[mnp]||x[i]==x[mnp]&&z[i]<z[mnp])mnp=i;
		if(mxp==0||y[i]>y[mxp]||y[i]==y[mxp]&&z[i]<z[mxp])mxp=i;
		if(x[i]<=x[mnp]&&y[i]>=y[mxp]&&(mmp==0||x[mmp]>x[mnp]||y[mmp]<y[mxp]||z[mmp]>z[i]))mmp=i;
		printf("%d\n",std::min(z[mnp]+z[mxp],x[mmp]>x[mnp]||y[mmp]<y[mxp]?0x7fffffff:z[mmp]));
	}
	}return 0;
}