#include <iostream>
#include <cstdio>
using namespace std;
int n,rest,l[200005],r[200005];
int now,ans;
int main(){
//	freopen("1041D.in","r",stdin);
//	freopen("1041D.out","w",stdout);
	cin>>n>>rest;
	for (int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	now=1,ans=r[1]-l[1]+rest;
	for (int i=2;i<=n;i++){
		rest-=l[i]-r[i-1];
		while(rest<=0){
			rest+=l[now+1]-r[now];
			now++;
		}
		ans=max(ans,r[i]-l[now]+rest);
	}
	cout<<ans<<endl;
}