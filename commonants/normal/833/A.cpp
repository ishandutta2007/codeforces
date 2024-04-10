#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;
const int MX=35,inf=0x3f3f3f3f;
int n,a,b;
int pa[MX],pb[MX],pca,pcb;
typedef long long LL;
inline int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b)a%=b,swap(a,b);
	return a;
}
namespace PRho{
	int prime[9]={2,3,5,7,11,13,17,19,23};
	unsigned int RR;
	int Pcnt;
	int p[MX];
	inline int R(int Mo){return (RR+=4179340454199820289ll)%Mo;}
	inline int mul(int x,int y,int Mo){
	    int tmp=(x*y-(int)((long double)x/Mo*y+0.5)*Mo);
	    return tmp<0?tmp+Mo:tmp;
	}
	inline int Pow(int x,int k,int Mo){
	    int ans=1;
	    for(;k;k>>=1,x=mul(x,x,Mo))if(k&1)ans=mul(ans,x,Mo);
	    return ans;
	}
	inline bool MR(int n){
	    if(n<=1)return false;
	    for(int i=0;i<9;i++)if(n==prime[i])return true;
	    int d=n-1;int tmp=0;
	    while((d&1)==0)d>>=1,tmp++;
	    for(int i=0;i<9;i++){
	        int x=Pow(prime[i],d,n),p=x;
	        for(int j=1;j<=tmp;j++){
	            x=mul(x,x,n);
	            if((x==1)&&(p!=1)&&(p!=n-1))return false;
	            p=x;
	        }
	        if(x!=1)return false;
	    }
	    return true;
	}
	inline int f(int x,int c,int Mo){return (mul(x,x,Mo)+c)%Mo;}
	//inline int gcd(int x,int y){return x==0?y:gcd(y%x,x);}
	inline int check(int c,int n){
	    int x=R(n),y=f(x,c,n),p=n;
	    while((x!=y)&&((p==n)||(p==1))){
	        if(x>y)p=gcd(n,x-y);
	        else p=gcd(n,y-x);
	        x=f(x,c,n);y=f(f(y,c,n),c,n);
	    }
	    return p;
	}
	inline void rho(int n){
	    if(n<=1)return;
	    if(MR(n)){p[++Pcnt]=n;return;}
	    while(true){
	        int tmp=check(R(n-1)+1,n);
	        if(tmp!=n && tmp!=1){rho(tmp),rho(n/tmp);return;}
	    }
	}
	inline void Rho(int n){
		Pcnt=0;rho(n);sort(p+1,p+Pcnt+1);
	}
}
using namespace PRho;


int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);int g=gcd(a,b);
		#define GG {puts("No");continue;}
		LL C=pow((double)a*b,1.0/3.0);
		LL D=(LL)a*b;
		while(C*C*C<D)++C;
		while(C*C*C>D)--C;
		if(C*C*C!=D)GG
		if(a%C||b%C)GG
		a/=C,b/=C;
		if((LL)a*b!=C)GG
		puts("Yes");continue;
		//Rho(a);memcpy(pa+1,p+1,sizeof(int)*Pcnt);pca=Pcnt;pa[pca+1]=inf;
		//Rho(b);memcpy(pb+1,p+1,sizeof(int)*Pcnt);pcb=Pcnt;pb[pcb+1]=inf;
		//for(int i=1;i<=pca;i++)fprintf(stderr,"%d ",pa[i]);fprintf(stderr,"\n");
		//for(int i=1;i<=pcb;i++)fprintf(stderr,"%d ",pb[i]);fprintf(stderr,"\n");
		/*bool flg=true;
		for(int ia=1,ib=1;ia<=pca||ib<=pcb;){
			int P=min(pa[ia],pb[ib]);
			int ac=0,bc=0;
			while(pa[ia]==P)++ac,++ia;
			while(pb[ib]==P)++bc,++ib;
			
			if((ac+bc)%3)GG
			
			if(ac<(ac+bc)/3)GG
			
			if(bc<(ac+bc)/3)GG
		}
		puts(flg?"Yes":"No");*/
	}
	return 0;
}