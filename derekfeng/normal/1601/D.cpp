#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,d,ans;
pii a[500004];
bool cmp(pii A,pii B){
	if(max(A.fi,A.se)!=max(B.fi,B.se))return max(A.fi,A.se)<max(B.fi,B.se);
	return A.fi<B.fi;
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)if(d<=a[i].fi)ans++,d=max(d,a[i].se);
	printf("%d",ans);
}