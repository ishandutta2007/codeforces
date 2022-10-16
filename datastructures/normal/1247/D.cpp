#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define inf 10000000000
#define int long long
using namespace std;
int n,a[1000005],k,book[1000005],book2[1000005],ans;
inline int pw(int a,int x){
	int ans=1;
	for (int i=1;i<=x;i++){
		ans*=a;
		if (ans>inf)return inf+1;
	}
	return ans;
}
inline int get(int i,int j){
	if (i==j)return book[i]*(book[i]-1)/2;
	return book[i]*book[j];
}
inline void work(int x){
	for (int i=1;i*i<=x;i++){
		if (x%i==0&&i<=100000&&x/i<=100000)
			ans+=get(i,x/i);
	}
	return;
}
inline int abcd(int now){
	int ans=1;
	for (int i=2;i*i<=now;i++){
		int tt=0;
		while(now%i==0)now/=i,tt++;
		if (tt%2==1)ans*=i;
	}
	ans*=now;
	return ans;
}
signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]),book[a[i]]++;
	if (k==2){
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++){
			int s=abcd(a[i]);
			ans+=book2[s];
			book2[s]++;
		}
		cout<<ans<<endl;
		return 0;
	} 
	for (int i=1;pw(i,k)<=inf;i++){
		int x=pw(i,k);
		work(x);
	}
	cout<<ans<<endl;
	return 0;
}