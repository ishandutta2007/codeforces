#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,m,a[N],b[N],num;bool flag1,flag2;LL ans;
priority_queue<int>q;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(b[1]<a[n]){
		puts("-1");return 0;
	}
	for(int i=1;i<=m;i++)ans+=b[i];
	if(b[1]==a[n])ans+=1ll*a[n-1]*m;
	else ans+=a[n],ans+=1ll*a[n-1]*(m-1);
	for(int i=1;i<n-1;i++)ans+=1ll*a[i]*m;
	cout<<ans;
	return 0;
}