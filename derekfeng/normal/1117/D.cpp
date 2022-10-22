#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
void read(int &x){
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void readi(ll &x){
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct matrix{
	int h,w;
	ll a[103][103];
};
matrix mymul(matrix A,matrix B){
	matrix C;
	C.h=A.h,C.w=B.w;
	for(int i=0;i<C.h;i++)for(int j=0;j<C.w;j++){
		C.a[i][j]=0;
		for(int k=0;k<A.w;k++){
			C.a[i][j]+=A.a[i][k]*B.a[k][j]%MOD;
		}
		C.a[i][j]%=MOD;
	}
	return C;
}
int m;
matrix mypow(ll n){
	matrix x,ans;
	x.h=m,x.w=m,ans.h=m,ans.w=m;
	for (int i=0;i<x.h;i++)for(int j=0;j<x.w;j++) x.a[i][j]=0,ans.a[i][j]=0;
	x.a[0][0]=1,x.a[0][m-1]=1;
	for (int i=1;i<x.h;i++) x.a[i][i-1]=1;
	for (int i=0;i<ans.h;i++) ans.a[i][i]=1;
	while (n>0){
		if(n%2==1){
			n--;
			ans=mymul(ans,x);
			continue;
		}
		n/=2;
		x=mymul(x,x);
	}
	return ans;
}
ll n;
int main(){
	readi(n),read(m);
	matrix f_;
	f_.h=m,f_.w=1;
	f_.a[0][0]=1;
	for (int i=1;i<m;i++) f_.a[i][0]=0;
	write(mymul(mypow(n),f_).a[0][0]);
}