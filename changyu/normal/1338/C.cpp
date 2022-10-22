#include<cstdio>
typedef long long ll;
const ll Key[12]={0,0,0,1,2,3,2,3,1,3,1,2};
ll n,nn,la,ans;int lg4,o0,o1;
//ll,clear
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%lld",&n);
	lg4=0;
	for(nn=n;nn;nn>>=2)++lg4;//printf("%d\n",lg4);
	la=0;
	ans=0;
	for(int j=0;j<lg4;j++){
	  nn=n-la*3;
	  if(nn<=(3ll<<(j<<1)))o0=1;
	  else{
		nn-=(3ll<<(j<<1));
		--nn;
		o0=(nn%(12ll<<(j<<1)))/(3ll<<(j<<1));
		++nn;
	  }
	  o1=(nn-1)%3;//printf("%d %d\n",o0,o1);
	  ans|=Key[o0*3+o1]<<(j<<1);
	  la+=1ll<<(j<<1);
	}printf("%lld\n",ans);
	}return 0;
}