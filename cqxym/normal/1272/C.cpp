#include<stdio.h>
#define R register int
#define L long long
char c[200000];
bool v[26];
inline L Calc(int x){
	return (L)x*(x+1)>>1;
}
int main(){
	int n,k;
	scanf("%d%d\n",&n,&k);
	for(R i=0;i!=n;i++){
		c[i]=getchar();
	}
	char t;
	for(R i=0;i!=k;i++){
		getchar();
		t=getchar();
		v[t-97]=true;
	}
	R l=0,r;
	L s=0;
	while(l<n){
		while(l<n&&v[c[l]-97]==false){
			l++;
		}
		if(l==n){
			break;
		} 
		r=l+1;
		while(r<n&&v[c[r]-97]==true){
			r++;
		}
		s+=Calc(r-l);
		l=r+1;
	}
	printf("%lld",s);
	return 0;
}