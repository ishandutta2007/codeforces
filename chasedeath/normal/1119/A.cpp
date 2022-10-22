#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=3e5+10,base=1e4;
int n,m;
int a[N];
int L[N],R[N],c[N],cnt;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==1||a[i]!=a[i-1]){
			R[cnt]=i-1;
			L[++cnt]=i,c[cnt]=a[i];
		}
	}
	R[cnt]=n;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=cnt;j>=1;j--)if(c[j]!=a[i]){
			ans=max(ans,R[j]-i);
			break;
		}
	}
	printf("%d\n",ans);
}