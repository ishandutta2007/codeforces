#include<bits/stdc++.h>
#define ll long long
#define M 317
#define N 100000
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[100002];
int b[100002];
int sum[63600002];
int main(){
	int T,n,i,j,k,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(k=-M;k<=M;++k){
		for(i=1;i<=n;++i){
			b[i]=a[i]+k*i;
			++sum[b[i]+M*N];
			if(sum[b[i]+M*N]>ans)ans=sum[b[i]+M*N];
		}
		for(i=1;i<=n;++i)sum[b[i]+M*N]=0;
	}
	for(i=1;i<=n;++i){
		for(j=i+1;j<=n&&j<=i+M;++j){
			if((a[j]-a[i])%(j-i)==0){
				int t=(a[j]-a[i])/(j-i);
				++sum[t+N];
				if(sum[t+N]+1>ans)ans=sum[t+N]+1;
			}
		}
		for(j=i+1;j<=n&&j<=i+M;++j){
			if((a[j]-a[i])%(j-i)==0){
				int t=(a[j]-a[i])/(j-i);
				sum[t+N]=0;
			}
		}
	}
	printf("%d\n",n-ans);
	return 0;
}