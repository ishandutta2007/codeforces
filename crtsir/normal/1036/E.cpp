#include<bits/stdc++.h>
using namespace std;
long long n,a1[1003],b1[1003],a2[1003],b2[1003];
long long ans;
long long gcd(long long x,long long y){if(x<y)swap(x,y);return y?gcd(y,x%y):x;}
map<pair<long long,long long>,long long>mp[1003];
bool in(long long i,long long x,long long y){
	if(max(a1[i],a2[i])>=x&&min(a1[i],a2[i])<=x&&max(b1[i],b2[i])>=y&&min(b1[i],b2[i])<=y)return 1;
	return 0;
}
int main(){
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a1[i]>>b1[i]>>a2[i]>>b2[i];
		ans=ans+gcd(fabs(a1[i]-a2[i]),fabs(b1[i]-b2[i]))+1;
	}
	for(long long i=0;i<n;i++)
		for(long long j=i+1;j<n;j++){
			if((a1[i]-a2[i])*(b1[j]-b2[j])==(a1[j]-a2[j])*(b1[i]-b2[i]))continue;
			long long tmp=(a2[i]*b1[i]-a1[i]*b2[i])*(a1[j]-a2[j])-(a2[j]*b1[j]-a1[j]*b2[j])*(a1[i]-a2[i]);
			if(tmp%((a1[i]-a2[i])*(b1[j]-b2[j])-(a1[j]-a2[j])*(b1[i]-b2[i])))continue;
			long long nx=-tmp/((a1[i]-a2[i])*(b1[j]-b2[j])-(a1[j]-a2[j])*(b1[i]-b2[i]));
			tmp=(b2[i]*a1[i]-b1[i]*a2[i])*(b1[j]-b2[j])-(b2[j]*a1[j]-b1[j]*a2[j])*(b1[i]-b2[i]);
			if(tmp%((b1[i]-b2[i])*(a1[j]-a2[j])-(b1[j]-b2[j])*(a1[i]-a2[i])))continue;
			long long ny=-tmp/((b1[i]-b2[i])*(a1[j]-a2[j])-(b1[j]-b2[j])*(a1[i]-a2[i]));
			if(in(i,nx,ny)&&in(j,nx,ny))
			{
				if(!mp[1001][make_pair(nx,ny)])ans++;
				ans-=(2-mp[i][make_pair(nx,ny)]-mp[j][make_pair(nx,ny)]);
				mp[i][make_pair(nx,ny)]=1;
				mp[j][make_pair(nx,ny)]=1;
				mp[1001][make_pair(nx,ny)]=1;
			}
		}
	cout<<ans;
}