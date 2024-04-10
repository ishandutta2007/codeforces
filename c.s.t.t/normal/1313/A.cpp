#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,x[7]={1,0,0,0,1,1,1},y[7]={0,1,0,1,0,1,1},z[7]={0,0,1,1,1,0,1},mx,ord[7];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c),mx=0;
		for(int i=0;i<7;i++)ord[i]=i;
		do{
			int res=0,p=a,q=b,r=c;
			for(int i=0;i<7;i++)if(p>=x[ord[i]]&&q>=y[ord[i]]&&r>=z[ord[i]])res++,p-=x[ord[i]],q-=y[ord[i]],r-=z[ord[i]];
			mx=max(mx,res);
		}while(next_permutation(ord,ord+7));
		printf("%d\n",mx);
	}
	return 0;
}