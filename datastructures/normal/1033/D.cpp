#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
#define mod 998244353
using namespace std;
int p[100005],tot;
int n,a[505];
map<int,int> c;
int ans=1;
int q2(int x){
	int l=1,r=2000000000,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (mid*mid<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	if (ans*ans==x)return ans;
	return -1;
}
int q3(int x){
	int l=1,r=2000000,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (mid*mid*mid<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	if (ans*ans*ans==x)return ans;
	return -1;
}
int q4(int x){
	int l=1,r=50000,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (mid*mid*mid*mid<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	if (ans*ans*ans*ans==x)return ans;
	return -1;
}
int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (q4(a[i])!=-1){
			p[++tot]=q4(a[i]);
			c[q4(a[i])]+=4;
			a[i]=1;
		}
		else if (q3(a[i])!=-1){
			p[++tot]=q3(a[i]);
			c[q3(a[i])]+=3;
			a[i]=1;
		}
		else if (q2(a[i])!=-1){
			p[++tot]=q2(a[i]);
			c[q2(a[i])]+=2;
			a[i]=1;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			if (a[i]!=a[j]&&gcd(a[i],a[j])>1)p[++tot]=gcd(a[i],a[j]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		if (a[i]==1)continue;
		for (int j=1;j<=tot;j++)
			if (a[i]%p[j]==0){
				c[p[j]]++;
				a[i]/=p[j];
				if (a[i]>1)c[a[i]]++,p[++tot]=a[i],a[i]=1;
				break;
			}
		if (a[i]==1)continue;
		int j=i;
		while(j<=n&&a[j]==a[i])j++;
		j--;
		ans=ans*(j-i+2)*(j-i+2)%mod;
		i=j;
	}
	for (map<int,int>::iterator it=c.begin();it!=c.end();it++)ans=ans*((*it).second+1)%mod;
	cout<<ans<<endl;
	return 0;
}