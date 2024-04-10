#include<bits/stdc++.h>
using namespace std;
const int B=400;
int n,a,b,m;
long long bs,sum[300003];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		bs+=a;
		sum[i+1]=a-b;
	}
	sort(sum+1,sum+n+1);
	for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1];
	scanf("%d",&m);
	unordered_map<long long,long long>mp;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(mp.find(1ll*x*n+y)!=mp.end())
			printf("%lld\n",mp[1ll*x*n+y]);
		else{
			long long res=-1;
			if(x<=y)
				for(int i=0;i<=n;i+=y)
					if((n-i)%x==0)
						res=max(res,bs-sum[i]);
					else;
			else
				for(int i=0;i<=n;i+=x)
					if((n-i)%y==0)
						res=max(res,bs-sum[n-i]);
			mp[1ll*x*n+y]=res;
			printf("%lld\n",res); 
		}
	}
}