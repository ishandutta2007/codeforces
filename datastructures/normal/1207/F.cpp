#include <iostream>
#include <cstdio>
#define size 700
using namespace std;
int q,opt,x,y,val[705][705],a[500005];
int main(){
	cin>>q;
	while(q--){
		scanf("%d%d%d",&opt,&x,&y);
		if (opt==1){
			a[x]+=y;
			for (int i=1;i<=size;i++)
				val[i][x%i]+=y;
		}
		else{
			if (x<=size)printf("%d\n",val[x][y]);
			else{
				int ans=0;
				for (int i=y;i<=500000;i+=x)ans+=a[i];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}