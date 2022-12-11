#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const double eps=1e-9;

int n; double L;
double a[100010];
void init(){
}
void solve(){
	n=read(),L=read();
	for (int i=1;i<=n;i++) a[i]=read();
	a[0]=0,a[n+1]=L;
	double res=0,A=1,B=1;
	int l=1,r=n; double P=0,Q=L;
	while (l<=r){
		double t1=(a[l]-P)/A;
		double t2=(Q-a[r])/B;
		if (fabs(t1-t2)<eps) res+=t1,A++,B++,P=a[l++],Q=a[r--];
		else if (t1<t2) res+=t1,A++,P=a[l++],Q-=t1*B;
		else res+=t2,B++,Q=a[r--],P+=t2*A;
	}
	res+=(Q-P)/(A+B);
	printf("%.10lf\n",res);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}