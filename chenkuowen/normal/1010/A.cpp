#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_N=5+1e3;
const double eps=1e-10;
double A,B,key[MAX_N],a[MAX_N],b[MAX_N],m;
int n;
bool judge(double k){
	k-=(m+k)/A;
//	printf("{%.7lf}",k);
	if(k+eps<0) return false;
	for(int i=1;i<n;++i){
		k-=(m+k)*key[i];
		if(k+eps<0) return false;
	}
	return k+eps>=(m+k)/B;
}
int main(){
	scanf("%d%lf",&n,&m);
	scanf("%lf",&A);
	for(int i=1;i<n;++i) scanf("%lf",&a[i]);
	scanf("%lf",&B);
	for(int i=1;i<n;++i) scanf("%lf",&b[i]);
	for(int i=1;i<n;++i)
		key[i]=(a[i]+b[i]-1)/(a[i]*b[i]);
	sort(key+1,key+n);
	if(!judge(1e9)){
		printf("-1\n");
		return 0;
	}
	double l=0,r=1e9;
	while(r-l>2e-7){
		double mid=(l+r)/2;
		if(judge(mid)) r=mid;
		else l=mid;
	}
	printf("%.8lf\n",(l+r)/2);
	return 0;
}