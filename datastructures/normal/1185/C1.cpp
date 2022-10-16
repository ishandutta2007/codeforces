#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
int n,t,now,a[200005],c[200005];
priority_queue <int>h;
signed main(){
	cin>>n>>t;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int tot=0,ans=0;
		while(now+a[i]>t){
			ans++;
			now-=h.top();
			c[++tot]=h.top();
			h.pop();
		}
		for (int j=1;j<=tot;j++)now+=c[j],h.push(c[j]);
		h.push(a[i]);now+=a[i];
		printf("%d ",ans);
	}
	cout<<endl;
	return 0;
}