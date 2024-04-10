#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int n,m;
char a[N+5];
int z[N+1];
void z_init(){
	int zl=0,zr=0;
	z[1]=n;
	for(int i=2;i<=n;i++)
		if(zr<i){
			while(i+z[i]<=n&&a[i+z[i]]==a[1+z[i]])z[i]++;
			zl=i;zr=i+z[i]-1;
		}
		else if(i+z[i-zl+1]-1<zr)z[i]=z[i-zl+1];
		else{
			z[i]=zr-i+1;
			while(i+z[i]<=n&&a[i+z[i]]==a[1+z[i]])z[i]++;
			zl=i;zr=i+z[i]-1;
		}
}
int d[N+1];
int main(){
	cin>>n>>m>>a+1;
	z_init();
	for(int i=1;i*m<=n;i++)
		if(z[i+1]>=i*(m-1)){
//			cout<<i<<" "<<i*m+min(i,z[i*m+1])<<"\n";
			d[i*m]++;
			if(i*m+min(i,z[i*m+1])+1<=n)d[i*m+min(i,z[i*m+1])+1]--;
		}
	int now=0;
	for(int i=1;i<=n;i++){
		now+=d[i];
		cout<<!!now;
	}
	return 0;
}
/*1
7 2
bcabcab
*/
/*2
21 2
ababaababaababaababaa
*/