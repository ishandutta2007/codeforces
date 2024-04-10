#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
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
	ll a[2][2];
};
matrix mymul(matrix A,matrix B){
	matrix C;
	C.h=A.h,C.w=B.w;
	for(int i=0;i<C.h;i++)for(int j=0;j<C.w;j++){
		C.a[i][j]=0;
		for(int k=0;k<A.w;k++)
			C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%MOD;
	}
	return C;
}
matrix mypow(ll n){
	matrix x,ans;
	x.h=2,x.w=2;
	x.a[0][0]=3,x.a[0][1]=1,x.a[1][0]=1,x.a[1][1]=3;
	ans.h=2,ans.w=2;
	ans.a[0][0]=1,ans.a[0][1]=0,ans.a[1][0]=0,ans.a[1][1]=1;
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
	readi(n);
	matrix f_;
	f_.h=2,f_.w=1;
	f_.a[0][0]=1,f_.a[1][0]=0;
	write(mymul(f_,mypow(n)).a[0][0]);
}