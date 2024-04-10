#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int t,n,m,k,a[100005],b[100005];
int l1,c[100005][2],l2,d[100005][2];
void ins1(int num){
	int cnt=1;
	while(num%m==0)num/=m,cnt*=m;
	if (l1==0||num!=c[l1][0])++l1,c[l1][0]=num,c[l1][1]=cnt;
	else c[l1][1]+=cnt;
	return;
}
void ins2(int num){
	int cnt=1;
	while(num%m==0)num/=m,cnt*=m;
	if (l2==0||num!=d[l2][0])++l2,d[l2][0]=num,d[l2][1]=cnt;
	else d[l2][1]+=cnt;
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		l1=l2=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ins1(a[i]);
		}
		cin>>k;
		for (int i=1;i<=k;i++){
			scanf("%d",&b[i]);
			ins2(b[i]);
		}
		int fg=1;
		if (l1!=l2)fg=0;
		for (int i=1;i<=l1&&fg==1;i++)
			if (c[i][0]!=d[i][0]||c[i][1]!=d[i][1])fg=0;
		if (fg==1)puts("YES");
		else puts("NO");
	}
	return 0;
}