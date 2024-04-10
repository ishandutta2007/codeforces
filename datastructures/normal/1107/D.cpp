#include <iostream>
#include <cstdio>
using namespace std;
int n,a[5205][5205],sum[5205][5205],ans;
char s[5205];
inline int S(register int xl,register int xr,register int yl,register int yr){
	return sum[xr][yr]-sum[xl-1][yr]-sum[xr][yl-1]+sum[xl-1][yl-1];
}
inline bool check(int len){
	for (register int i=len;i<=n;i+=len)
		for (register int j=len;j<=n;j+=len){
			int nows=S(i-len+1,i,j-len+1,j);
			if (nows!=0&&nows!=len*len)return 0;
		}
	return 1;
} 
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=n/4;j++){
			int l=(j-1)*4+1,r=j*4,num=0;
			if (s[j]>='0'&&s[j]<='9')num=s[j]-'0';
			else num=s[j]-'A'+10;
			while(r>=l){
				a[i][r]=num%2;
				num/=2;
				r--;
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
	for (int i=1;i<=n;i++)
		if (n%i==0&&check(i))ans=i;
	cout<<ans<<endl;
	return 0;
}