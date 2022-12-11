#include <iostream>
#include <cstdio>
using namespace std;
int n,sums,f[15],cnt;char t,opera;
int main(){
	scanf("%d",&n);
	for(int i=0;i<10;++i)f[i]=3;
	for(int i=1;i<=n;++i){
		while(opera=getchar(),opera!='&'&&opera!='|'&&opera!='^');
		scanf("%d",&sums);
		if (opera == '&') {
			for(int j=0;j<10;++j)
				if (!(sums&1<<j)) f[j]=0;
		}
		else if(opera =='|') {
			for (int j=0;j<10;++j)
				if(sums&1<<j) f[j]=1;
		}
		else if(opera == '^') {
			for(int j=0;j<10;++j)
				f[j]^=bool(sums&1<<j);
		}
	}
	int ta,to,tx;
	ta=1023,to=0,tx=0;
	for(int i=0;i<10;++i)
		if(f[i]==0)ta-=1<<i;
		else if(f[i]==1)to+=1<<i;
		else if(f[i]==2)tx+=1<<i;
	if(ta<1023)++cnt;
	if(to)++cnt;
	if(tx)++cnt;
	printf("%d\n",cnt);
	if(ta<1023)printf("& %d\n",ta);
	if(to)printf("| %d\n",to);
	if(tx)printf("^ %d\n",tx);
	return 0;
}