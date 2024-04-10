#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4010,mod=1e9+9;
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}
int i,j,k,n,m,a,b;
ll jc[maxn],ny[maxn];
ll ans=0;
void init(){
	jc[0]=1;for(int i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mod;
	ny[maxn-1]=ksm(jc[maxn-1],mod-2);for(int i=maxn-2;i>=0;i--)ny[i]=ny[i+1]*(i+1)%mod;
}
ll C(int A,int B){
	if(B>A)return 0;
	return jc[A]*ny[B]%mod*ny[A-B]%mod;
}
ll make(int A,int B){
	return C(A-1,B-1)%mod;
}
int main(){
	cin>>n>>a>>b;
	init();
	for(i=2;i<n;i++)
		for(j=i;j<n;j++){
			int lenb=(j-i)+1,lena=n-lenb;
			ans+=make(b,lenb)*make(a,lena)%mod;
//			cout<<"i="<<i<<" j="<<j<<" ans="<<ans<<endl;
//			cout<<make(b,lenb)<<' '<<make(a,lena)<<endl;
			ans%=mod;
		}
	cout<<ans*(jc[a]*jc[b]%mod)%mod<<endl;
	return 0;
}