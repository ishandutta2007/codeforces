#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int n,k;
long long hsh[1000003],power[1000003],a[1000003];
string s;
bool check(long long l,long long r,long long d){ 
	long long hashl=hsh[l+d]-hsh[l];
	if(hashl<0) 
		hashl+=mod;
	hashl=hashl*power[r-l]%mod;
	long long hashr=hsh[r+d]-hsh[r];
	if(hashr<0) 
		hashr+=mod;
	if(hashl!=hashr) 
		return 0;
	return 1;
} 
int main(){
	cin>>n>>k>>s;
	hsh[0]=0;
	power[0]=1;
	for(int i=1;i<1000003;i++)power[i]=(power[i-1]*128)%mod;
	for(int i=0;i<n;i++)hsh[i+1]=(hsh[i]+s[i]*power[i])%mod;
	for(int i=0;i<=n/k;i++){
		int l=0,r=n+1;
		while(l+1<r){
			long long mid=(l+r)/2;
			if(i+mid<=n&&check(0,i,mid))l=mid;else r=mid;
		}
		if(k*i<=min(k*i+i,i+l)){
			a[k*i]++;
			a[min(k*i+i,i+l)+1]--;
		}
	}
	for(int i=0;i<n;i++)a[i+1]+=a[i];
	for(int i=1;i<=n;i++)cout<<(a[i]>0)?1:0;
}