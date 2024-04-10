#include<stdio.h>
#define R register int
int p[200001],f[200002],pos[200001];
inline int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
int ct;
inline void Merge(int &x,int y){
	if(GetF(x)!=GetF(y)){
		f[f[x]]=f[y];
		ct--;
	}
}
inline void Solve(){
	int n,x;
	ct=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",p+i);
		pos[p[i]]=i;
		f[i]=i;
	}
	for(R i=1;i<=n;i++){
		x=pos[i];
		ct++;
		if(p[x-1]<i&&x>1){
			Merge(x,x-1);
		}
		if(p[x+1]<i&&x<n){
			Merge(x,x+1);
		}
		if(ct==1){
			printf("1");
		}else{
			printf("0");
		}
	}
	puts("");
}
int main(){
	int t;
	scanf("%d\n",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}