#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;
#define R register int
#define I inline int
#define L long long
int a[200001],ct[100001],k,id;
struct Prime{
	int p,x;
};
vector<Prime>G[200001];
inline L PowMod(int a,int b){
	L s=1,o=a;
	while(b>0){
		if((b&1)>0){
			if(s>1e5){
				return 0;
			}
			s*=o;
		}
		b>>=1;
		if(o>1e5){
			return 0;
		}
		o*=o;
	}
	if(s>1e5){
		return 0;
	}
	return s;
}
I Calc(int x,int a){
	if(x%a>0){
		return x;
	}
	int s=0;
	do{
		x/=a;
		s++;
	}while(x%a==0);
	Prime P;
	P.p=a;
	P.x=s%k; 
	G[id].push_back(P);
	return x;
}
I Dev(int x){
	int t=std::sqrt(x);
	x=Calc(x,2);
	for(R i=3;i<=t&&x>1;i+=2){
		x=Calc(x,i);
	}
	if(x>1){
		Prime P;
		P.p=x;
		P.x=1;
		G[id].push_back(P);
	}
	return x;
}
int main(){
	int n;
	scanf("%d%d",&n,&k);
	for(R i=0;i<n;i++){
		scanf("%d",&a[i]);
		id=i;
		a[i]=Dev(a[i]);
	}
	L ans=0;
	for(R i=0;i<n;i++){
		L pw=1,pp=1;
		int l=G[i].size();
		for(R j=0;j<l;j++){
			pw*=PowMod(G[i][j].p,(k-G[i][j].x)%k);
			pp*=PowMod(G[i][j].p,G[i][j].x);
		}
		if(pw>0&&pp>0){
			ans+=ct[pw];
			ct[pp]++;
		}
	}
	printf("%lld",ans);
	return 0;
}