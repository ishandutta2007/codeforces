#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,d,m,a[N],n1,n2;LL s1[N],s2[N],ans;
int main(){
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]<=m)++n1,s1[n1]=s1[n1-1]+a[i];
		else ++n2,s2[n2]=s2[n2-1]+a[i];
	int mn=(n2+d)/(d+1),mx=min((n+d)/(d+1),n2);
	for(int i=n2-mx;i<=n2-mn;i++){
		int dd=max(min((n2-i-1)*d-i,n1),0);//cout<<dd<<" ";
		ans=max(ans,s1[n1]-s1[dd]+s2[n2]-s2[i]);
	}
	cout<<ans;
	return 0;
}
// 5 2 11
// 8 10 11 11 5