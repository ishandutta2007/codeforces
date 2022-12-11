#include<bits/stdc++.h>
using namespace std;
int x[1000001],n;
int main(){
	int t;scanf("%d",&t);while(t--){
		scanf("%d",&n);
		memset(x,0,sizeof x); x[0]=1;
		int ok=0,t=0;
		for(int i=2;i<=n+1;++i){
			int a; scanf("%d",&a); a=abs(a);
			if(x[a])ok=1;
			for(int j=0;j<=t;++j)if(x[j]&&x[j]<i)x[max(a-j,j-a)]=x[a+j]=i;
			t+=a;
		} puts(ok?"YES":"NO");
	}
}