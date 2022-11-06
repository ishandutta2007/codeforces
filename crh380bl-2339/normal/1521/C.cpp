#include<bits/stdc++.h>
//int p[10005];
using namespace std;
int ASK(int opt,int x,int i,int j){
	printf("? %d %d %d %d\n",opt,i,j,x);
	fflush(stdout);
	int res;
	//if(opt==1)res=max(min(x,p[i]),min(x+1,p[j]));
	//else res=min(max(x,p[i]),max(x+1,p[j]));
	scanf("%d",&res);
	return res;
}
int a[10005];
int main(){
	int T,n,i,j,id1,id2,id3,t,k;
	scanf("%d",&T);
	while(T--){
		id1=id2=id3=0;
		scanf("%d",&n);
		//for(i=1;i<=n;++i)scanf("%d",&p[i]);
		for(i=1;i<=n;i+=2){
			if(i!=n){
				t=ASK(1,n-1,i,i+1);
				j=i+1;
			}
			else{
				t=ASK(1,n-1,i,1);
				j=1;
			}
			if(t==n){
				id1=j;
				break;
			}
			if(t==n-1){
				t=ASK(1,n-1,j,i);
				if(t==n){
					id1=i;
					break;
				}
				k=j+1;
				if(k>n)k=1;
				t=ASK(1,n-1,i,k);
				if(t==n)id1=k;
				else if(t==n-1)id2=i;
				else id2=j;
				break;
			}
		}
		if(id1){
			a[id1]=n;
			for(i=1;i<=n;++i){
				if(i!=id1){
					a[i]=ASK(2,1,i,id1);
				}
			}
		}
		else{
			a[id2]=n-1;
			for(i=1;i<=n;++i){
				if(i!=id2){
					a[i]=ASK(2,1,i,id2);
					if(a[i]==n-1)a[i]=n;
				}
			}
		}
		printf("!");
		for(i=1;i<=n;++i)printf(" %d",a[i]);
		puts("");
		fflush(stdout);
	}
	return 0;
}