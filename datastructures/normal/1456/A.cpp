#include <iostream>
#include <cstdio>
using namespace std;
int t,n,p,k,x,y;
char s[1000005];
int f[1000005],cnt[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>p>>k;
		scanf("%s",s+1);
		cin>>x>>y;
		for (int i=1;i<=n;i++)
			if (s[i]=='1')cnt[i%k]++;
		int ans=1000000000;
		for (int i=1;i<p;i++)
			if (s[i]=='1')cnt[i%k]--;
		for (int i=0;i+p<=n;i++){
			int num=(n-(p+i))/k+1-cnt[(p+i)%k];
			ans=min(ans,y*i+x*num);
			if (s[i+p]=='1')cnt[(i+p)%k]--;
		}
		cout<<ans<<endl;
		for (int i=0;i<k;i++)cnt[i]=0;
	}
	return 0;
}