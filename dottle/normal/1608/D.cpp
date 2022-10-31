#include<bits/stdc++.h>
#define int long long
const int mod=998244353,N=500005;
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

main(){
	ios::sync_with_stdio(false);
	int n;cin>>n;
	init();
	int w=0,b=0,W=0,B=0,td=1,fl1=0,fl2=0,fl3=0;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		if(s[0]==s[1])if(s[0]!='?')td*=0;else td=td*2%mod;
		if(s[0]=='W')w++,fl3=1,fl1=1;
		if(s[0]=='B')b++,fl3=1,fl2=1;
		if(s[1]=='W')W++,fl3=1,fl2=1;
		if(s[1]=='B')B++,fl3=1,fl1=1;
	}
	int ans=0;
	if(fl2^fl1)ans++;
	if(!fl3)ans+=2;
	for(int i=0;i<=n;i++){
		if(i<max(B,w)||n-i<min(b,W))continue;
		int t=i-w,p=n-w-b,T=i-B,P=n-W-B;
		ans+=C(p,t)*C(P,T)%mod;
	} 
	cout<<(ans-td+mod)%mod<<endl;
}