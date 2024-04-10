#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N,n;
struct Point{
	ll x,y;
	bool operator<(const Point b)const{return x<b.x||(x==b.x&&y>b.y);}
}A[100005],B[100005];
bool calc(int u,int v,int w){
	return (B[v].y-B[u].y)*(B[w].x-B[v].x)<=(B[w].y-B[v].y)*(B[v].x-B[u].x);
}
int stk[100005],len;

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%lld%lld",&A[i].x,&A[i].y),A[i].y-=A[i].x*A[i].x;
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++) if(i==1||A[i].x!=A[i-1].x) B[++n]=A[i];
	for(int i=1;i<=n;i++){
		while(len>1&&calc(stk[len-1],stk[len],i)) len--;
		stk[++len]=i;
	}
	printf("%d\n",len-1);
}