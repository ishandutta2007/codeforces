#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int n;
char a[N+5];
int z[N+1];
void z_init(){
	int zl=0,zr=0;
	for(int i=2;i<=n;i++)
		if(zr<i){
			while(i+z[i]<=n&&a[i+z[i]]==a[1+z[i]])z[i]++;
			if(z[i])zl=i,zr=i+z[i]-1;
		}
		else if(i+z[i-zl+1]<=zr)z[i]=z[i-zl+1];
		else{
			z[i]=zr-i+1;
			while(i+z[i]<=n&&a[i+z[i]]==a[1+z[i]])z[i]++;
			zl=i;zr=i+z[i]-1;
		}
}
int main(){
	cin>>a+1;
	n=strlen(a+1);
	z_init();
	int mx=0;
	for(int i=2;i<=n;i++)mx=max(mx,min(n-i,z[i]));
	for(int i=2;i<=n;i++)if(i+z[i]-1==n&&z[i]<=mx){
		for(int j=i;j<=n;j++)cout<<a[j];
		return 0;
	}
	puts("Just a legend");
	return 0;
}
/*1
fixprefixsuffix
*/
/*2
abcdabc
*/