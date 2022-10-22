#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,p[200010],x,a,y,b,k;

inline int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}

inline bool check(int xx)
{
	int lcm=a*b;
	if(a>b) lcm/=gcd(a,b);
	else lcm/=gcd(b,a);
	int num1=xx/lcm;
	int num2=xx/a-num1,num3=xx/b-num1;
	int sum=0;
	bool flag=false;
	for(int i=1;i<=num1;i++){
		sum+=p[i]*(x+y);
		if(sum>=k){
			return true;
		}
	}
	for(int i=num1+1;i<=num1+num2;i++){
		sum+=p[i]*x;
		if(sum>=k){
			return true;
		}
	}
	for(int i=num1+num2+1;i<=num1+num2+num3;i++){
		sum+=p[i]*y;
		if(sum>=k){
			return true;
		}
	}
	return false;
}

signed main()
{
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++){cin>>p[i];p[i]/=100;}
		cin>>x>>a>>y>>b>>k;
		if(x<y){
			swap(x,y);
			swap(a,b);
		}
		sort(p+1,p+n+1);
		reverse(p+1,p+n+1);
		int l=1,r=n,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}