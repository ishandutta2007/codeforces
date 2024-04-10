#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db EPS=1e-7;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int num[7][8]={ {0,0,0,1,1,1,1,0},
				{0,1,1,0,0,1,1,0},
				{1,0,1,0,1,0,1,0},
				{0,1,1,1,1,0,0,0},
				{1,0,1,1,0,1,0,0},
				{1,1,0,0,1,1,0,0},
				{0,0,0,0,0,0,1,0},
			  };
int a[7],res=1e8;
db f[7][8];
void Gauss_Jordan(){
	for (int i=0;i<7;i++) for (int j=0;j<8;j++) f[i][j]=num[i][j];
	for (int i=0;i<7;i++){
		if (abs(f[i][i])<EPS)
			for (int j=i+1;j<7;j++) if (fabs(f[j][i])>EPS){
				swap(f[j],f[i]);break;
			}
		for (int j=7;j>=i;j--) f[i][j]/=f[i][i];
		for (int j=0;j<7;j++) if (i!=j){
			for (int k=i+1;k<8;k++) f[j][k]-=f[j][i]*f[i][k];
			f[j][i]=0.0;
		}
	}
	int ans[7],len=0;
	for (int i=0;i<7;i++){
		if (f[i][7]<0 || f[i][7]!=floor(f[i][7])) return;
		ans[i]=f[i][7],len+=ans[i];
	}
	if (len<res){
		res=len;
		swap(a,ans);
	}
}
string ans1,ans2,ans3;
int main(){
	for (int i=0;i<6;i++) read(num[i][7]);
	num[6][7]=0;
	for (int i=0;i<=1e5;i++){
		num[6][7]=i;
		Gauss_Jordan();
	}
	if (res==1e8) puts("-1");
	else{
		write(res),puts("");
		for (int i=0;i<res;i++) putchar('a');puts("");
		for (int i=0;i<a[0];i++) putchar('a');
		for (int i=0;i<a[1];i++) putchar('a');
		for (int i=0;i<a[2];i++) putchar('a');
		for (int i=0;i<a[3];i++) putchar('b');
		for (int i=0;i<a[4];i++) putchar('b');
		for (int i=0;i<a[5];i++) putchar('b');
		for (int i=0;i<a[6];i++) putchar('b');puts("");
		for (int i=0;i<a[0];i++) putchar('a');
		for (int i=0;i<a[1];i++) putchar('b');
		for (int i=0;i<a[2];i++) putchar('b');
		for (int i=0;i<a[3];i++) putchar('a');
		for (int i=0;i<a[4];i++) putchar('a');
		for (int i=0;i<a[5];i++) putchar('b');
		for (int i=0;i<a[6];i++) putchar('b');puts("");
		for (int i=0;i<a[0];i++) putchar('b');
		for (int i=0;i<a[1];i++) putchar('a');
		for (int i=0;i<a[2];i++) putchar('b');
		for (int i=0;i<a[3];i++) putchar('a');
		for (int i=0;i<a[4];i++) putchar('b');
		for (int i=0;i<a[5];i++) putchar('a');
		for (int i=0;i<a[6];i++) putchar('b');
	}
}