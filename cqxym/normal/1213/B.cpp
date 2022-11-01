#include<cstdio>
int a[150000],c[1000001];
int Lowb(int x){
	return x&-x;
} 
void Add(int x){
	for(int i=x;i<=1e6;i+=Lowb(i)){
		c[i]++;
	}
}
int Get(int x){
	for(int i=x;i>0;i-=Lowb(i)){
		if(c[i]>0){
			return 1;
		}
	}
	return 0;
}
void Solve(){
	int n,i,s=0,M=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>M){
			M=a[i];
		}
	}
	for(i=1;i<=M;i++){
		c[i]=0;
	}
	for(i=n-1;i>-1;i--){
		s+=Get(a[i]-1);
		Add(a[i]);
	}
	printf("%d\n",s);
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		Solve();
	}
	return 0;
}