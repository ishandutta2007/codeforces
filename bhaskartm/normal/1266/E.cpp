#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans=0;
map<int,int> p[200005];
int main(){
	int i,x,y,z;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),ans+=a[i];
	scanf("%d",&m);
	while (m--){
		scanf("%d%d%d",&x,&y,&z);
		if (p[x].count(y)){
			a[p[x][y]]++;
			if (a[p[x][y]]>0) ans++;
		}
		a[z]--;
		if (a[z]>=0) ans--;
		p[x][y]=z;
		printf("%lld\n",ans);
	}
	return 0;
}