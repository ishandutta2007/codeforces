#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int n,k[500],x;
int ans=(int)1e9;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&k[i]);
	for(int i=1;i<=n;i++){
		ll t=0;
		for(int j=1;j<=k[i];j++){
			scanf("%d",&x); 
			t+=5*x+15;
		}
		if (t<ans) ans=t;
	}
	printf("%d\n",ans);
	return 0;
}