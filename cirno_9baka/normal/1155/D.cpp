#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
typedef long long ll;
int n,i,x,a[500005];
ll f[500005][3],ans;
int main(){
	scanf("%d %d",&n,&x);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i][0]=max(f[i-1][0],0ll)+a[i];
		f[i][1]=max(max(f[i-1][1],f[i-1][0]),0ll)+1ll*a[i]*x;
		f[i][2]=max(max(max(f[i-1][1],f[i-1][0]),f[i-1][2]),0ll)+a[i];
		ans=max(ans,max(max(f[i][0],f[i][1]),f[i][2]));
	}
	cout<<ans;
}