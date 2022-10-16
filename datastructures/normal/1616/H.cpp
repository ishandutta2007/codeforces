#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define mod 998244353
using namespace std;
int n,x,a[150005],pow_2[150005];
int getval(int x,int y){
	return ((pow_2[x+y]-1)-(pow_2[x]-1)-(pow_2[y]-1)+2*mod)%mod;
}
int calc2(int w,vector<int> s1,vector<int> s2){
	if (s1.size()==0||s2.size()==0)return 0;
	vector<int> s1_0,s1_1,s2_0,s2_1;
	for (int i=0;i<s1.size();i++)
		if (!(s1[i]&(1<<w)))s1_0.push_back(s1[i]);
		else s1_1.push_back(s1[i]);
	for (int i=0;i<s2.size();i++)
		if (!(s2[i]&(1<<w)))s2_0.push_back(s2[i]);
		else s2_1.push_back(s2[i]);
	int ans=0;
	if (w==0){
		if (x&(1<<w))return getval(s1.size(),s2.size());
		return (getval(s1_0.size(),s2_0.size())+getval(s1_1.size(),s2_1.size()))%mod;
	}
	if (x&(1<<w)){
		ans=(getval(s1_0.size(),s2_0.size())+getval(s1_1.size(),s2_1.size()))%mod;
		int v1=calc2(w-1,s1_0,s2_1),v2=calc2(w-1,s1_1,s2_0);
		ans=(ans+v1*(pow_2[s1_1.size()]+pow_2[s2_0.size()]-1))%mod;
		ans=(ans+v2*(pow_2[s1_0.size()]+pow_2[s2_1.size()]-1))%mod;
		ans=(ans+v1*v2)%mod;
		return ans;
	}
	else ans=(calc2(w-1,s1_0,s2_0)+calc2(w-1,s1_1,s2_1))%mod;
	return ans;
}
int calc1(int w,vector<int> c){
	if (c.size()==0)return 0;
	vector<int> c0,c1;
	for (int i=0;i<c.size();i++)
		if (!(c[i]&(1<<w)))c0.push_back(c[i]);
		else c1.push_back(c[i]);
	int ans=0;
	if (w==0){
		if (x&(1<<w))return pow_2[c.size()]-1;
		return ((pow_2[c0.size()]-1)+(pow_2[c1.size()]-1))%mod;
	}
	if (x&(1<<w)){
		ans=((pow_2[c0.size()]-1)+(pow_2[c1.size()]-1))%mod;
		ans=(ans+calc2(w-1,c0,c1))%mod;
	}
	else ans=(calc1(w-1,c0)+calc1(w-1,c1))%mod;
	return ans;
}
signed main(){
	cin>>n>>x;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	pow_2[0]=1;
	for (int i=1;i<=n;i++)pow_2[i]=pow_2[i-1]*2%mod;
	vector<int> awa;
	for (int i=1;i<=n;i++)awa.push_back(a[i]);
	cout<<calc1(30,awa)<<endl;
	return 0;
}