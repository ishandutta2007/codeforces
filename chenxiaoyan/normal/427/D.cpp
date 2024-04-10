#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=5000,M=5000;
int n,m,s;
char a[N+5],b[M+5],c[2*N+M+5];
int z[2*N+M+1];
void z_init(){
	int zl=0,zr=0;
	for(int i=2;i<=s;i++)
		if(zr<i){
			z[i]=0;
			while(i+z[i]<=s&&c[i+z[i]]==c[1+z[i]])z[i]++;
			if(z[i])zl=i,zr=i+z[i]-1;
		}
		else if(i+z[i-zl+1]-1<zr)z[i]=z[i-zl+1];
		else{
			z[i]=zr-i+1;
			while(i+z[i]<=s&&c[i+z[i]]==c[1+z[i]])z[i]++;
			zl=i;zr=i+z[i]-1;
		}
//	cout<<"z";for(int i=2;i<=s;i++)cout<<z[i];puts("");
}
int buc1[N+1],buc2[N+1];
int main(){
	cin>>a+1>>b+1;
	n=strlen(a+1);m=strlen(b+1);
	int ans=inf;
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j<=n;j++)c[++s]=a[j];
		c[++s]='!';
		for(int j=1;j<=n;j++)c[++s]=a[j];
		c[++s]='@';
		for(int j=1;j<=m;j++)c[++s]=b[j];
		c[s+1]=0;
//		cout<<c+1<<"\n";
		z_init();
		memset(buc1,0,sizeof(buc1));memset(buc2,0,sizeof(buc2));
//		for(int j=n-i+3;j<=2*n-i+2;j++)cout<<c[j];cout<<" ";for(int j=2*n-i+4;j<=s;j++)cout<<c[j];puts("");
		for(int j=n-i+3;j<=2*n-i+2;j++)buc1[z[j]]++;
		for(int j=2*n-i+4;j<=s;j++)buc2[z[j]]++;
		for(int j=n-i+1;j;j--){
//			printf("buc1[%d]=%d buc2[%d]=%d\n",j,buc1[j],j,buc2[j]);
			if(buc1[j]==1&&buc2[j]==1)ans=min(ans,j);
			buc1[j-1]+=buc1[j];buc2[j-1]+=buc2[j];
		}
//		puts("");
//		cout<<"ans="<<ans<<"\n";
	}
	printf("%d",ans<inf?ans:-1);
	return 0;
}
/*1
apple
pepperoni
*/
/*2
lover
driver
*/
/*3
bidhan
roy
*/
/*4
testsetses
teeptes
*/
/*5
aaaaaa
aaaaaa
*/