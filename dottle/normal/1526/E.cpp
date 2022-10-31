#include<bits/stdc++.h>
#define int long long
const int N=500050,mod=998244353;
using namespace std;

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
	if(n<m)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}

int n,k,a[N],p[N],cnt; 

main(){
	ios::sync_with_stdio(false);
	init();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[a[i]]=i;
	p[n]=-1;
	for(int i=1;i<n;i++)
		if(p[a[i]+1]>p[a[i+1]+1])
			cnt++;
	cout<<C(k+n-1-cnt,n);
}