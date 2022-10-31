#include<bits/stdc++.h>
const int N=10005;
using namespace std;
 
int y[N],h[N],ans,p,a[N],n,m;
 
main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)printf("and 1 %d\n",i);
	for(int i=2;i<=n;i++)printf("or 1 %d\n",i);
	printf("or 2 3\n");
	fflush(stdout);
	for(int i=2;i<=n;i++)scanf("%d",&y[i]);
	for(int i=2;i<=n;i++)scanf("%d",&h[i]);
	scanf("%d",&p);
	for(int i=0,j=1;i<31;i++,j<<=1){
		int fl=0;
		for(int k=2;k<=n;k++){
			if(y[k]>>i&1){
				ans|=j,fl=1;
				break;
			}
			if(!(h[k]>>i&1)){
				fl=1;
				break;
			}
		}
		if(!fl){
			int nw=p>>i&1;
			ans+=(!nw)<<i;
		}
	}
	a[1]=ans;
	for(int i=2;i<=n;i++){
		for(int j=0;j<31;j++)
			if(ans>>j&1)
				a[i]|=y[i]&(1<<j);
			else
				a[i]|=h[i]&(1<<j);
	}
	sort(a+1,a+1+n);
	printf("finish %d\n",a[m]);
	fflush(stdout);
}