#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50,M=1e9;
int t,n,lim,a[N],num;LL c[N];
int main(){
	scanf("%d",&t);
	for(lim=2;;lim++){
		c[lim]=1ll*lim*(lim-1)/2;
		if(c[lim]>1e9){lim--;break;}
	}
	while(t--){
		scanf("%d",&n);num=0;
		for(int i=lim;i>=2;i--)
			while(n>=c[i])a[i]++,n-=c[i],num=max(num,i);
		for(int i=num;i;i--){
			while(a[i])putchar('1'),a[i]--;
			putchar('3');
		}
		puts("7");
	}
	return 0;
}