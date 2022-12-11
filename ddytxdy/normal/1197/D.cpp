#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
int n,m,k,a[N];LL ans,now;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=0;j<m;j++){
		LL now=0;
		for(int i=j?j:m;i<=n;i++){
			if(i%m==j){
				if(now<0)now=0;
				now-=k;
			}
			now+=a[i];
			ans=max(ans,now);
		}
	}
	cout<<ans;
	return 0;
}