#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
#define R register int
#define L long long
vector<L>A;
inline int Dev(L &x,L a){
	int s=0;
	do{
		x/=a;
		s++;
	}while(x%a==0);
	return s;
}
inline void Add(L p,int pow){
	L s=1;
	while(pow!=0){
		if((pow&1)==1){
			s*=p;
		}
		p*=p;
		pow>>=1;
	}
	A.push_back(s);
}
int t;
L ans=1e13;
L Max(L a,L b){
	return a>b?a:b;
}
inline void DFS(L a,L b,int x){
	if(x==t){
		if(a<ans&&b<ans){
			ans=Max(a,b);
		}
		return;
	}
	DFS(a*A[x],b,x+1);
	DFS(a,A[x]*b,x+1);
}
int main(){
	L n,k;
	scanf("%lld",&n);
	k=n;
	t=sqrt(n);
	if((n&1)==0){
		Add(2,Dev(n,2));
	}
	for(R i=3;i<=t&&n>1;i+=2){
		if(n%i==0){
			Add(i,Dev(n,i));
		}
	}
	if(n>1){
		Add(n,1);
	}
	t=A.size();
	DFS(1,1,0);
	printf("%lld %lld",ans,k/ans);
	return 0;
}