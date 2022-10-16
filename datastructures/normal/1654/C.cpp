#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define int long long
using namespace std;
int t,n,a[200005];
map<int,int> c;
int cnt;
int q[200005],d[200005],head,tail;
void upd(int x,int y){
	if (y==0)return;
	if (q[tail]==x)d[tail]+=y;
	else{
		++tail;
		q[tail]=x;
		d[tail]=y;
	} 
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		c.clear();
		int sum=0;
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]),c[a[i]]++,sum+=a[i];
		cnt=0;
		head=tail=1;
		q[1]=sum,d[1]=1;
		while(head<=tail){
			int val=q[head],nowd=d[head];
			head++;
			int qwq=min(nowd,c[val]);
			cnt+=qwq,nowd-=qwq,c[val]-=qwq;
			if (val==1)continue;
			upd((val+1)/2,nowd);
			upd(val/2,nowd);
		} 
		if (cnt==n)puts("YES");
		else puts("NO");
		for (int i=0;i<=tail;i++)q[i]=d[i]=0;
	}
	return 0;
}