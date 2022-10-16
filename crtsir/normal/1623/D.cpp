#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)
			ret=1ll*ret*x%mod;
		times>>=1;
		x=1ll*x*x%mod;
	}return ret;
}
int main(){
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		int rb,rd,cb,cd,p;
		cin>>rb>>rd>>cb>>cd>>p;rb--;rd--;cb--;cd--; 
		int dr=1,dc=1;
		bool ok=0;
		int nwp=1,inv100=mypow(100,mod-2),suc=1ll*inv100*p%mod,fai=1ll*inv100*(100-p)%mod,ex=0,cnt=0,tmpb=rb,tmpd=rd,nxtb=-1,nxtd=-1;
		while(1){
			if(rb+dr>=n||rb+dr<0)dr=-dr;
			if(rd+dc>=m||rd+dc<0)dc=-dc;
			if(rb==tmpb&&rd==tmpd&&nxtb==rb+dr&&nxtd==rd+dc)
				break;
			if(rb==cb||rd==cd){
				ex=(ex+1ll*suc*nwp%mod*cnt%mod)%mod;
				nwp=1ll*nwp*fai%mod;
			}
			cnt++;
			if(rb+dr>=n||rb+dr<0)dr=-dr;
			if(rd+dc>=m||rd+dc<0)dc=-dc;
			rb+=dr;rd+=dc;
			if(ok==0)nxtb=rb,nxtd=rd;
			ok=1;
		}
		fai=nwp;suc=(mod+1-nwp)%mod;
		ex=1ll*ex*mypow(suc,mod-2)%mod;
		cout<<(ex+1ll*fai*cnt%mod*mypow(suc,mod-2))%mod<<endl;
	}
}