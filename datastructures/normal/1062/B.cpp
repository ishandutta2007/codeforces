#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,pr[10005],cnt[10005],tot,ans1=1,ans2,flag;
inline int ask(int n){
	if (n==1)return 0;
	for (int i=1;i;i++)
		if ((1<<i)>=n)return i;
}
inline int work(int x){
	if (x==1)flag=1;
	int ans=0;
	while(x!=1){
		if (x%2==1)flag=1;
		x=(x+1)/2;
		ans++;
	}
	return ans;
}
inline bool check(){
	for (int i=1;i<=tot;i++)
		if (cnt[i]!=1)return 0;
	return 1;
}
signed main(){
	cin>>n;
	for (int i=2;i*i<=n;i++){
		if (n%i!=0)continue;
		tot++;
		pr[tot]=i;
		while(n%i==0)n/=i,cnt[tot]++;
	}
	if (n>1)tot++,pr[tot]=n,cnt[tot]=1;
	for (int i=1;i<=tot;i++)
		ans1*=pr[i];
	for (int i=1;i<=tot;i++){
		if (cnt[i]==1){
			flag=1;
			continue;
		}
		ans2=max(ans2,work(cnt[i]));
	}
	for (int i=1;i<=tot;i++)
		if (cnt[i]!=cnt[1])flag=1;	
	if (ans2!=0)cout<<ans1<<' '<<ans2+flag<<endl;
	else cout<<ans1<<' '<<0<<endl;
	return 0;
}