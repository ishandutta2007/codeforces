/*








*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000000,M=1000000;
int n,m,s;
char a[N+5],b[M+5],ra[N+5],rb[N+5],c[N+1+N+5];
void con(char str1[],char str2[]){
	s=0;
	for(int i=1;i<=n;i++)c[++s]=str1[i];
	c[++s]=1;
	for(int i=1;i<=n;i++)c[++s]=str2[i];
}
int rev_pos(int pos){return n+1-pos;}
int z1[N+1+N+1],kmp[N+1+N+1],z2[N+1+N+1];
void z_init(int z[]){
	int zl=0,zr=0;
	for(int i=2;i<=s;i++)
		if(zr<i){
			while(i+z[i]<=s&&c[i+z[i]]==c[1+z[i]])z[i]++;
			if(z[i])zl=i,zr=i+z[i]-1;
		}
		else if(i+z[i-zl+1]<=zr)z[i]=z[i-zl+1];
		else{
			z[i]=zr-i+1;
			while(i+z[i]<=s&&c[i+z[i]]==c[1+z[i]])z[i]++;
			zl=i;zr=i+z[i]-1;
		}
}
void kmp_init(){
	for(int i=2;i<=s;i++){
		int now=kmp[i-1];
		while(now&&c[now+1]!=c[i])now=kmp[now];
		if(c[now+1]==c[i])kmp[i]=now+1;
	}
}
int main(){
	scanf("%[^\n]",a+1);getchar();scanf("%[^\n]",b+1);
	n=strlen(a+1);m=strlen(b+1);
	if(n!=m)return puts("-1 -1"),0;
	memcpy(ra+1,a+1,n+1);reverse(ra+1,ra+n+1);
	memcpy(rb+1,b+1,n+1);reverse(rb+1,rb+n+1);
	con(b,a);z_init(z1);
	con(ra,b);kmp_init();
	con(a,rb);z_init(z2);
	for(int i=n-1;i;i--)if(z2[n+1+rev_pos(n)]>=i){
		int mxl=z1[n+1+i+1],mxr=kmp[n+1+n-i];
		if(mxl+mxr>=n-i)return cout<<i-1<<" "<<n-mxr,0;
	}
	puts("-1 -1");
	return 0;
}
/*1
Die Polizei untersucht eine Straftat im IT-Bereich.
untersucht eine Straftat.hciereB-TI mi  ieziloP eiD
*/
/*2
cbaaaa
aaaabc
*/
/*3
123342
3324212
*/