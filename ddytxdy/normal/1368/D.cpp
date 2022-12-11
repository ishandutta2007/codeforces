#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,a[40];LL ans;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		for(int j=0;j<30;j++)if(x>>j&1)a[j]++;
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=0;j<30;j++)
			if(a[j])x|=1<<j,a[j]--;
		ans+=1ll*x*x;
	}
	cout<<ans;
	return 0;
}