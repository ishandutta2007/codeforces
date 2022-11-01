#include<iostream>
using namespace std;
#define R register int
inline void Min(int&x,const int y){
	if(x>y){
		x=y;
	}
}
int f[500][501],d[500],a[500];
int main(){
	int n,l,k,ans=1100000000;
	cin>>n>>l>>k;
	for(R i=0;i!=n;i++){
		cin>>d[i];
	}
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	for(R i=1;i!=n;i++){
		for(R j=0;j<=i;j++){
			f[i][j]=1100000000;
		}
		for(R j=0;j!=i;j++){
			for(R k=0;k<=j;k++){
				Min(f[i][k+i-j-1],f[j][k]+a[j]*(d[i]-d[j]));
			}
		}
		for(R j=1;j<=i;j++){
			if(f[i][j-1]<f[i][j]){
				f[i][j]=f[i][j-1];
			}
		}
	}
	for(R i=0;i!=n;i++){
		int t=n-1-i;
		if(t<=k){
			t=k-t;
			Min(ans,f[i][i<t?i:t]+a[i]*(l-d[i]));
		}
	}
	cout<<ans;
	return 0;
}