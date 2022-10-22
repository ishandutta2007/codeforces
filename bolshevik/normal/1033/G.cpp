#include<cstdio>
#include<algorithm>
using namespace std;
int n,v_[110],m;long long v[110],F,S;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&v[i]);
	for(int i=2;i<=m*2;++i){
		for(int j=1;j<=n;++j) v_[j]=v[j]%i;
		sort(v_+1,v_+n+1);
		v_[0]=0;v_[n+1]=i-1;
		for(int j=n+1,l,r,L,R,Parity=0;j;--j,Parity^=1){
			l=v_[j-1]+1;r=min(v_[j],m);
			if(!Parity) l=max(l,v_[n]/2+1);
			else l=max(l,v_[n-1]/2+1);
			if((L=max(l,i-r))<=(R=min(r,i-l)))
				if(Parity) F+=R-L+1;
				else S+=R-L+1;
		}
	}
	printf("%lld %lld %lld %lld",(m*1ll*m-F-S)/2,(m*1ll*m-F-S)/2,F,S);
	return 0;
}