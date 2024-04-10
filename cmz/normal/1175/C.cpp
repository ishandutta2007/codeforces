#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,k,x,y,mid,ans,anss;
int a[maxn];
int main(){
	int t; 
	scanf("%d",&t);
	while (t--){
		ans=2147483647;
		scanf("%d%d",&n,&k); 
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		for (int i=1;i<=n;++i){
			x=a[i]; if (i+k>n) break; y=a[i+k];
			mid=(x+y)/2;
			int now=max(mid-x,y-mid);
			if (now<ans) {
				ans=now;
				anss=mid;
			}
		}
		printf("%d\n",anss);
	}
	int aa;
}