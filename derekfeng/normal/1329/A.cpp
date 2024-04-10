#include <bits/stdc++.h>
using namespace std;
int n,m,x,now=n+1,l[100005],p[100005],i;
int main(){
	cin>>n>>m;
	now=n+1;
	for (int j=1;j<=m;j++) scanf("%d",&l[j]);
	reverse(l+1,l+1+m);
	while (m--){
		i++;
		x=l[i];
		if (m+x>n){
			puts("-1");return 0;
		}
		p[i]=max(m+1,now-x);
		now=p[i];
	}
	if (now!=1) puts("-1");
	else{
		reverse(p+1,p+1+i);
		for (int j=1;j<=i;j++) printf("%d ",p[j]);
	}
}