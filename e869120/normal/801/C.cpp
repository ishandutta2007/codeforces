#include<bits/stdc++.h>
using namespace std;
int n;long double a[100005],b[100005],p;
int main(){
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	long double L=1e-12,R=1e12,M;
	for(int i=0;i<100;i++){
		M=(L+R)/2;
		bool OK=true;long double s=0;
		for(int j=0;j<n;j++){
			long double E=M*a[j];
			long double F=(E-b[j])/p;
			if(F<0)F=0;
			s+=F;
		}
		if(OK==true && s<=M)L=M;
		else R=M;
	}
	if(M>=1e11)cout<<"-1"<<endl;
	else printf("%.12Lf\n",M);
	return 0;
}