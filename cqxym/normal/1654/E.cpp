#include<stdio.h>
#include<map>
using namespace std;
#define R register int
#define I inline
int a[100000],ctp[100000],ctn[100000];
inline int Solve(const int n){
	int res=0;
	for(R i=-70;i<=70;i++){
		map<int,int>Q;
		for(R j=0;j!=n;j++){
			Q[a[j]+i*j]++;
		}
		for(auto T:Q){
			if(T.second>res){
				res=T.second;
			}
		}
	}
	for(R i=0;i!=n;i++){
		for(R j=1;j!=1430&&i+j<n;j++){
			int d=a[i+j]-a[i];
			if(d%j==0){
				d/=j;
				int&c=d<0?ctn[-d]:ctp[d];
				c++;
				if(c>=res){
					res=c+1;
				}
			}
		}
		for(R j=1;j!=1430&&i+j<n;j++){
			int d=a[i+j]-a[i];
			if(d%j==0){
				d/=j;
				int&c=d<0?ctn[-d]:ctp[d];
				c--;
			}
		}
	}
	return res;
}
int main(){
	int n,ans;
	scanf("%d",&n);
	if(n==1){
		putchar('0');
		return 0;
	}
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
		a[i]--;
	}
	ans=Solve(n);
	printf("%d",n-ans);
	return 0;
}