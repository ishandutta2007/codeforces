#include<iostream>
using namespace std;
#define min(a,b) a<b?a:b
int main(){
	int s,x1,x2;
	cin>>s>>x1>>x2;
	int t1,t2;
	cin>>t1>>t2;
	int p,d;
	cin>>p>>d;
	int q=d;
	if (t2<=t1){
		long long  tmp=(x2-x1)*t2;
		if (tmp<0) tmp=-tmp;
		cout<<tmp;
		return 0;
	}else{
		if (x1>x2){
			x1=s-x1;
			x2=s-x2;
			q=-q;
			p=s-p;
		}
		long long time2;
		long long time1=(x2-x1)*t2;
		if (p<=x1){
			if (q==1){
				time2=(x2-p)*t1;
			}else{
				time2=(p+x2)*t1;
			}
			cout<<(min(time1,time2));
		}else{
			if (q==1){
				time2=(s-p+s+x2)*t1;
			}else{
				time2=(p+x2)*t1;
			}
			cout<<(min(time1,time2));
		}
	}
	return 0;
}