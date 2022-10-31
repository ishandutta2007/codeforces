#include<bits/stdc++.h>
#define int long long
const int N=1000050,mod=998244353;
using namespace std;
struct num{int x;num(){cin>>x;}operator int(){return x;}};

int n,a[N],m;

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

bool chk(int k){
	vector<int> f(m+1);
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=i;j<=m;j+=i)
			cnt+=a[j];
		f[i]=C(cnt,k);
	}
	for(int i=m;i;i--)
		for(int j=i+i;j<=m;j+=i)
			f[i]-=f[j],f[i]%=mod;
	return f[1];
}

main(){
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		num x;a[x]=1;
		m=max(m,(int)x);
	}
	for(int i=1;i<=10;i++)
		if(chk(i))
			cout<<i,exit(0);
	cout<<-1;
}