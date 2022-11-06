#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int a,b;
	node(int _a=0,int _b=1){
		a=_a;b=_b;
	}
	bool operator <(node z)const{
		return a*z.b<b*z.a;
	}
};
char s[500005];
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
map<node,int>M;
int Ans[500002];
int main(){
	int T,n,D,K,g,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		D=K=0;M.clear();
		for(i=1;i<=n;++i)Ans[i]=0;
		for(i=1;i<=n;++i){
			if(s[i]=='D')++D;
			else ++K;g=gcd(D,K);
			node p=node(D/g,K/g);
			if(!M.count(p)){
				Ans[i]=1;
				M[p]=i;
			}
			else{
				Ans[i]=Ans[M[p]]+1;
				M[p]=i;
			}
		}
		for(i=1;i<=n;++i)printf("%d ",Ans[i]);
		puts("");
	}
	return 0;
}