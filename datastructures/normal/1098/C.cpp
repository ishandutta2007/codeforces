#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;
int n,s,a[100005];
bool check(int x){
	int now=1,d=1,qwq=0,sum=0;
	for (int i=1;i<=n;i++){
		a[i]=d;
		sum+=d;
		qwq++;
		if (qwq==now)d++,qwq=0,now=now*x;
	}
	if (sum<=s)return 1;
	return 0;
}
int gs(int l,int r){
	return (l+r)*(r-l+1)/2;
}
vector<int> e[100005];
int fa[100005];
void out(int x){
	int now=1,d=1,qwq=0,sum=0;
	for (int i=1;i<=n;i++){
		if (gs(d,n-i+d)+sum<=s){
			for (int j=i;j<=n;j++){
				a[j]=d;
				sum+=a[j];
				d++;
			}
			break;
		}
		a[i]=d;
		sum+=d;
		qwq++;
		if (qwq==now)d++,qwq=0,now=now*x;
	}
	if (sum<s){
		int pos=0;
		for (int i=2;i<=n;i++)
			if (a[i]==a[i-1])pos=i;
		for (int i=pos;i<=pos+(s-sum)-1;i++)a[i]++;
	}
	for (int i=1;i<=n;i++)e[a[i]].push_back(i);
	int awa=0;
	for (int i=2;i<=n;i++){
		if (a[i]!=a[i-1])awa=0;
		fa[i]=e[a[i]-1][awa];
		awa=(awa+1)%e[a[i]-1].size();
	}
	for (int i=2;i<=n;i++)printf("%lld ",fa[i]);
	puts("");
	return;
}
signed main(){
	cin>>n>>s;
	if (s<(2*n)-1||s>n*(n+1)/2){
		puts("No");
		return 0;
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<"Yes"<<endl;
	out(ans);
	return 0;
}