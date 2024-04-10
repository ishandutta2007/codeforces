#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int n,a[2][o],f[2][o][2],lst[2],Lst[2];char s[2][o];
int main(){
	scanf("%d%s%s",&n,s[0]+1,s[1]+1);
	for(int i=1;i<=n;++i) a[0][i]=s[0][i]-48,a[1][i]=s[1][i]-48;
	lst[0]=lst[1]=n+2;
	for(int i=n;i;--i){
		for(int k=2;k--;) for(int j=2;j--;){
			Lst[0]=lst[0];Lst[1]=lst[1];
			if(a[!j][i]&&!k) Lst[!j]=i;
			if(Lst[!j]+1<Lst[j]) f[j][i][k]=a[j][i]+max(f[!j][Lst[!j]][Lst[!j]==i],f[j][Lst[j]][0]);
			else if(Lst[!j]>=Lst[j]) f[j][i][k]=a[j][i]+f[j][Lst[j]][0];
			else f[j][i][k]=a[j][i]+max(f[j][Lst[j]][0],f[!j][Lst[!j]+1][1]+a[!j][Lst[!j]]);
		}
		for(int j=0;j<2;++j) if(a[j][i]) lst[j]=i;
	}
	printf("%d",f[0][1][0]);
	return 0;
}