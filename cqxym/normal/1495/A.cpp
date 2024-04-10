#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define R register int
int a[100000],b[100000];
inline void Solve(){
	int n,x,y,ct1=0,ct2=0;
	cin>>n;
	for(R i=1;i<=n<<1;i++){
		cin>>x>>y;
		x=abs(x);
		y=abs(y);
		if(x==0){
			a[ct1]=y;
			ct1++;
		}else{
			b[ct2]=x;
			ct2++;
		}
	}
	sort(a,a+n);
	sort(b,b+n);
	double ans=0;
	for(R i=0;i!=n;i++){
		ans+=sqrt((long long)a[i]*a[i]+(long long)b[i]*b[i]);
	}
	printf("%.9lf\n",ans);
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}