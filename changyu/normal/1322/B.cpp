#include<bits/stdc++.h>
#define max(a,b)((a)>(b)?(a):(b))
const int N=4e5+3,K=25,A=1<<K;
int n,a[N],c[A+1],d[A+1],s,t,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int j=0;j<K;j++){
	  s=0;
	  for(int i=0;i<(1<<j+1);i++)c[i]=0;
	  for(int i=1;i<=n;i++)++c[a[i]&(1<<j+1)-1];
	  for(int i=(1<<j+1)-1;~i;i--)d[i]=(c[i]&1)^d[i+1];
	  for(int i=0;i<(1<<j);i++){
		if(i){
		  s^=c[i]&(d[1<<j]^d[max(i+1,(1<<j)-i)]);
		  s^=c[i+(1<<j)]&d[max(i+(1<<j)+1,(1<<j+1)-i)];
		}
		if(i+i>=(1<<j)){
		  s^=(((long long)c[i]*(c[i]-1))>>1)&1;
		  s^=(((long long)c[i+(1<<j)]*(c[i+(1<<j)]-1))>>1)&1;
		}
		s^=c[i]&(d[1<<j]^d[(1<<j+1)-i]);
	  }
	  ans|=s*(1<<j);
	}
	printf("%d\n",ans);
	return 0;
}