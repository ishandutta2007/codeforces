#include<iostream>
using namespace std;
int a[32],s[32],p[32],n,k,z,lst;
inline int calc(int x){
	int res=0;
	for(int i=1;i<32;i<<=1) if(x&i) res|=i*i;
	return res; 
}
int main(){
	for(int i=1;i<32;++i) a[i]=i&-i;
	for(int i=1;i<32;++i) p[s[i]=s[i-1]^a[i]]=i;
	cin>>n>>k;
	for(int i=1;i<=n;++i,cout<<endl) for(int j=1;j<n;++j) cout<<calc(a[j])<<" ";
	for(int i=1;i<n;++i,cout<<endl) for(int j=1;j<=n;++j) cout<<calc(a[i])*2<<" ";
	for(int t,x,y;k--;cout<<p[x]+1<<" "<<p[y]+1<<endl){
		cin>>t;x=y=0;t^=lst;lst=t;
		for(int i=1;i<32;i<<=1){
			if(t&(i*i)) y|=i;
			if(t&(i*i*2)) x|=i;
		}
	}
	return 0;
}