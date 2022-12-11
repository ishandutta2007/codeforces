#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int m,ans;LL n,k,a[N];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i];
	int now=0;
	for(int i=1;i<=m;i++){
		int j=i;
		while(j<m&&(a[j+1]-now-1)/k==(a[j]-now-1)/k)j++;
		ans++;now=i=j;
	}
	printf("%d\n",ans);
	return 0;
}