#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+10;
int n;
long long a[MAXN],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int i=1;
	while(i<=n){
		ans++; //
		if(i==n)break; //
		long long x=0,y=0;
		long long pre1=0,pre2=0;
		// 
		if(a[i]!=-1)x=a[i];
		else{
			pre1++;
			i++;
			while(i<=n){
				if(a[i]!=-1){
					x=a[i];break;
				}
				pre1++;
				i++;
			}
		}
		if(!x)break;
		// 
		i++;
		while(i<=n){
			if(a[i]!=-1){
				y=a[i];break;
			}
			pre2++;
			i++;
		}
		long long d=0;
		if(y){
			d = (y-x)/(pre2+1);
		}
		if(y && d*(pre2+1)==(y-x) && x-pre1*d > 0){
			//()() 
			long long v=y;
			i++;
			while(i<=n){
				v=v+d;
				if(v<1)break;
				if(a[i]!=-1 && a[i]!=v)break;
				i++;
			}
		}else{
			//b0 
			continue;
		}
	}
	printf("%lld",ans);
	return 0;
}