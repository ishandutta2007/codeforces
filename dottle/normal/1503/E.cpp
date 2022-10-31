#include<bits/stdc++.h>
#define int long long
const int N=100050,mod=998244353;
using namespace std;

void add(int&x,int y){
	x+=y;if(x>=mod)x-=mod;if(x<0)x+=mod;
}
int jc[N],ij[N],iv[N]; 
int C(int n,int m){
    if(n<m||n<0)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}
int W(int n,int m){
	return C(n+m,n);
}
int n,m,ans;
int S(int a,int b){
	return W(a-1,b-1)*W(a,m-b)%mod;
}

main(){
	init();
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int ns=0;
		for(int j=2;j<=m;j++){
			add(ans,ns*S(i,j)%mod);
			add(ans,S(n-i,m-(j-1)+1)*S(i,j)%mod);
			if(j>1)add(ns,S(n-i,m-(j-1)+1));
		}
	}
	swap(n,m);
	for(int i=1;i<n;i++){
		int ns=0;
		for(int j=1;j<=m;j++){
			add(ans,ns*S(i,j)%mod);
			if(j>1)add(ns,S(n-i,m-(j-1)+1));
		}
	}
	cout<<ans*2%mod<<endl;
}