#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll A[100005];
int F[62][100005];
int id[100005];
int nowk;
bool cmp(int a,int b){
	return (A[a]&((1LL<<nowk)-1))<(A[b]&((1LL<<nowk)-1));
}
int sum[2][100005];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%lld",&A[i]);
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++) A[i]=A[N]-A[i],id[i]=i;
	memset(F,63,sizeof(F));
	F[0][0]=0;
	for(int k=0;k<=60;k++){
		nowk=k;
		sort(id+1,id+N+1,cmp);
		for(int i=1;i<=N;i++){
			sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1];
			sum[(A[id[i]]>>k)&1][i]++;
		}
		for(int i=0;i<=N;i++){
			int w,ni;
			w=sum[1][N-i]+sum[0][N]-sum[0][N-i],ni=sum[1][N]-sum[1][N-i];
			F[k+1][ni]=min(F[k+1][ni],F[k][i]+w);
			w=sum[0][N-i]+sum[1][N]-sum[1][N-i],ni=N-sum[0][N-i];
			F[k+1][ni]=min(F[k+1][ni],F[k][i]+w);
		}
	}
	printf("%d\n",F[61][0]);
}