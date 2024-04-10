#include<stdio.h>
#include<queue>
using namespace std;
#define R register int
#define ll long long
ll f[200002];
int k;
struct WIFI{
	int id;
	ll cost;
};
deque<WIFI>Q,P;
void Add(int x){
	WIFI t;
	int l=x-k;
	if(l<1){
		l=1;
	}
	t.cost=x+P.front().cost;
	t.id=x;
	while(Q.empty()==false&&(Q.back().cost>=t.cost||Q.back().id+k<x)){
		Q.pop_back();
	}
	Q.push_back(t);
}
void PAdd(int x){
	WIFI t;
	t.cost=f[x];
	t.id=x;
	while(P.empty()==false&&(P.back().cost>=t.cost||P.back().id+k+1<x)){
		P.pop_back();
	}
	P.push_back(t);
}
void Clear(int x){
	while(Q.empty()==false&&Q.front().id+k<x){
		Q.pop_front();
	}
	while(P.empty()==false&&P.front().id+k+1<x){
		P.pop_front();
	}
}
ll Min(ll x,ll y){
	return x<y?x:y;
}
int main(){
	int n;
	scanf("%d%d\n",&n,&k);
	char c;
	P.push_back({0,0});
	for(R i=1;i<=n;i++){
		c=getchar();
		Clear(i);
		if(c=='1'){
			Add(i);
		}
		f[i]=f[i-1]+i;
		if(Q.empty()==false){
			WIFI p=Q.front();
			f[i]=Min(f[i],p.cost);
		}
		PAdd(i);
	}
	printf("%lld",f[n]);
	return 0;
}