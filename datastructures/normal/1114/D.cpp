#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,c[5005],m=5000,_n,_c[5005],f[5005][5005];
int main(){
	cin>>_n;
	for (int i=1;i<=_n;i++)cin>>_c[i];
	for (int i=1;i<=_n;i++)
		if (_c[i]!=_c[i-1])c[++n]=_c[i];
	for (int len=2;len<=n;len++)
		for (int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if (c[i]==c[j])f[i][j]=f[i+1][j-1]+1;
			else f[i][j]=min(f[i+1][j]+1,f[i][j-1]+1);
		}
	cout<<f[1][n]<<endl;
	return 0;
}