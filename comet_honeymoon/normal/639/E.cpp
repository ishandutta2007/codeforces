#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll T;
struct node{
	int p,t;
	ll Lt,Rt;
}A[150005];
bool cmp1(node a,node b){return 1LL*b.p*a.t<1LL*a.p*b.t;}
bool cmp2(node a,node b){return a.p<b.p;}

bool check(double mid){
	double mval=0.0,mval2=0.0;
	for(int i=1;i<=N;i++){
		if(A[i].p!=A[i-1].p) mval=mval2,mval2=0.0;
		if((double)A[i].p*(T-mid*A[i].Rt)<mval) return 0;
		mval2=max(mval2,A[i].p*(T-mid*A[i].Lt));
	}
	return 1;
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i].p);
	for(int i=1;i<=N;i++) scanf("%d",&A[i].t);
	sort(A+1,A+N+1,cmp1);
	ll st=0,ed=0;
	for(int i=1;i<=N;){
		int j=i;while(j<=N&&1LL*A[j+1].p*A[i].t==1LL*A[i].p*A[j+1].t) j++;
		for(int k=i;k<=j;k++) A[k].Lt=st+A[k].t,ed+=A[k].t;
		for(int k=i;k<=j;k++) A[k].Rt=ed;
		st=ed;i=j+1;
	}T=ed;
	sort(A+1,A+N+1,cmp2);
	double L=0,R=1,mid;
	while(L+1e-11<R){
		mid=(L+R)/2;
		if(check(mid)) L=mid;
		else R=mid;
	}
	printf("%.10lf\n",L);
}