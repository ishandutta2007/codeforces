#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[500005],cnt0;
int c[500005],tot;
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		cnt0=0;
		while(n+cnt0>1){
			int _cnt0=0;
			if (cnt0>0)_cnt0=cnt0-1;
			tot=0;
			int fir=2;
			if (cnt0>0)fir=1;
			for (int i=fir;i<=n;i++){
				if (a[i]-a[i-1]==0)_cnt0++;
				else c[++tot]=a[i]-a[i-1];
			} 
			cnt0=_cnt0;
			sort(c+1,c+1+tot);
			n=tot;
			for (int i=1;i<=n;i++)a[i]=c[i];
		}
		if (cnt0>0)puts("0");
		else printf("%d\n",a[1]);
	}
	return 0; 
}