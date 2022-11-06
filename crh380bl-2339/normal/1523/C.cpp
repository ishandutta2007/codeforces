#include<bits/stdc++.h>
using namespace std;
int q[1005],cnt=0;
int main(){
	int T,n,x,i,j;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&x);
			if(i==1){
				q[cnt=1]=1;
			}
			else{
				if(x==1)q[++cnt]=1;
				else{
					while(cnt>=1&&q[cnt]!=x-1)--cnt;
					q[cnt]=x;
				}
			}
			for(j=1;j<cnt;++j)printf("%d.",q[j]);printf("%d\n",q[cnt]);
		}
	}
	return 0;
}