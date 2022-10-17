#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,a[1000005],mx,pos;
int c[1000005],ans[1000005],_ans[1000005];
int pre(int x){
	if (x==1)return n;
	return x-1;
}
int nxt(int x){
	if (x==n)return 1;
	return x+1;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]),mx=max(mx,a[i]);
	if (mx==0){
		puts("YES");
		for (int i=1;i<=n;i++)printf("1 ");
		puts("");
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (a[i]==mx&&a[pre(i)]<mx)pos=i;
	if (pos==0)puts("NO");
	else{
		puts("YES");
		int _pos=pos;
		for (int i=n;i>=1;i--)c[i]=a[pos],pos=pre(pos);
		ans[n]=c[n];
		for (int i=n-1;i>=1;i--){
			if (i==n-1&&c[i]==0)ans[i]=ans[i+1]*2;
			else ans[i]=ans[i+1]+c[i];
		}
		pos=nxt(_pos);
		for (int i=1;i<=n;i++)_ans[pos]=ans[i],pos=nxt(pos);
		for (int i=1;i<=n;i++)printf("%lld ",_ans[i]);
		puts("");
	}
	return 0;
}