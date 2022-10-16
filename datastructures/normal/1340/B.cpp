#include <iostream>
#include <cstdio>
using namespace std;
string t[10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
int n,k;
string s[2005];
int c[2005][10];
int f[2005][2005];
int qwq(string x,string y){
	int fg=1,cnt=0;
	for (int i=0;i<7;i++){
		if (x[i]>y[i])fg=0;
		if (x[i]!=y[i])cnt++;
	}
	if (fg==0)return -1;
	return cnt;
}
void out(int now,int nowk){
	if (now>n)return;
	for (int i=9;i>=0;i--)
		if (c[now][i]!=-1&&c[now][i]<=nowk&&f[now+1][nowk-c[now][i]]==1){
			putchar('0'+i);
			out(now+1,nowk-c[now][i]);
			return;	
		}
	return;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		for (int j=0;j<10;j++)c[i][j]=qwq(s[i],t[j]);
	}
	f[n+1][0]=1;
	for (int i=n;i>=1;i--)
		for (int j=0;j<=k;j++)
			for (int l=0;l<10;l++)
				if (c[i][l]!=-1&&c[i][l]<=j)f[i][j]|=f[i+1][j-c[i][l]];
	if (f[1][k]==0)puts("-1");
	else out(1,k);
	return 0;
}