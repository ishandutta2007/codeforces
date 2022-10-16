#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int f[85][85][3501];//pos=i,num=j,cnt=k
int n,a[85],pos[85],tot,ans[3201];
int main(){
	cin>>n; 
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==1)pos[++tot]=i;
	}
	if (tot==0){
		for (int i=0;i<=n*(n-1)/2;i++)cout<<0<<' ';
		cout<<endl;
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	memset(ans,0x3f,sizeof(ans));
	f[0][0][0]=0;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=i&&j<=tot;j++)
			for (register int k=abs(i-pos[j]);k<=n*(n-1)/2;k++){
				for (register int l=0;l<i;l++)
					f[i][j][k]=min(f[i][j][k],f[l][j-1][k-abs(i-pos[j])]+(i-l-1)*(i-l-2)/2);
				if (j==tot)ans[k]=min(ans[k],f[i][j][k]+(n-i)*(n-i-1)/2);
			}
	for (int i=1;i<=n*(n-1)/2;i++)ans[i]=min(ans[i],ans[i-1]);
	for (int i=0;i<=n*(n-1)/2;i++)cout<<(n-tot)*(n-tot-1)/2-ans[i]<<' ';
	cout<<endl;
	return 0;
}