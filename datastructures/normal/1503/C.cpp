#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int a,c,id;
}d[100005];
int n,now,ans;
inline bool cmp(node a,node b){
	return a.a<b.a;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d%d",&d[i].a,&d[i].c),d[i].id=i,ans+=d[i].c;
	sort(d+1,d+1+n,cmp);
	now=1;
	while(now<n){
		int id=n;
		for (int i=now+1;i<=n;i++)
			if (d[i].a+d[i].c>d[now].a+d[now].c){
				id=i;
				break;
			}
		ans+=max(0ll,d[id].a-d[now].a-d[now].c);
		now=id;
	}
	cout<<ans<<endl;
	return 0;
}