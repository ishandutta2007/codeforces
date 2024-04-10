#include<bits/stdc++.h>
using namespace std;
int main(){
	int A,B,C,D,T; scanf("%d",&T);
	while(T--){
		bool f[4];
		memset(f,0,sizeof(f));
		scanf("%d%d%d%d",&A,&B,&C,&D);
		if((A+B)&1){
			if(A>0||D>0) f[0]=1;
			if(B>0||C>0) f[1]=1;
		}else{
			if(A>0||D>0) f[3]=1;
			if(B>0||C>0) f[2]=1;
		}
		for(int i=0;i<4;++i)
			if(f[i]) printf("Ya ");
			else printf("Tidak ");
		puts("");
	}
	return 0;
}