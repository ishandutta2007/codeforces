#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,cnt=60,opt,c[105],tot;
inline int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
inline int rnd(int x){
	return (rand()*rand()+rand())%x+1; 
}
int main(){
	srand(time(NULL));
	cin>>n;
	int l=1,r=1e9,mx=0;
	while(l<=r){
		int mid=(l+r)/2;
		cout<<'>'<<' '<<mid<<endl;	
		fflush(stdout);
		cnt--;
		cin>>opt;
		if (opt==0)mx=mid,r=mid-1;
		else l=mid+1;
	}
	c[++tot]=mx;
	for (int i=1;i<=cnt;i++){
		cout<<'?'<<' '<<rnd(n)<<endl;
		fflush(stdout);
		cin>>opt;
		c[++tot]=opt;
	}
	sort(c+1,c+1+tot);
	int ans=c[2]-c[1];
	for (int i=2;i<=tot;i++)
		ans=gcd(ans,c[i]-c[i-1]);
	cout<<'!'<<' '<<mx-ans*(n-1)<<' '<<ans<<endl;
	return 0;
}