/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
int n,qu;
int a[N+1];
map<int,int> add[N+1];
signed main(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)scanf("%lld",a+i),ans+=a[i];
	cin>>qu;
	while(qu--){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(add[x][y])a[add[x][y]]++,ans+=a[add[x][y]]>0,add[x][y]=0;
		if(z)a[z]--,ans-=a[z]>=0,add[x][y]=z;
		printf("%lld\n",ans);
	}
	return 0;
}