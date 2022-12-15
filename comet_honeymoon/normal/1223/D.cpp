#include<bits/stdc++.h>
using namespace std;

int T;
int N,ANS;
int A[300005],L[300005],R[300005];
int F[300005];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++) L[i]=R[i]=0;
		for(int i=1;i<=N;i++){
			scanf("%d",&A[i]);
			if(!L[A[i]]) L[A[i]]=i;
			R[A[i]]=i;
		}
		sort(A+1,A+N+1);N=ANS=unique(A+1,A+N+1)-A-1;
		for(int i=1;i<=N;i++){
			F[i]=1;
			if(i>=2&&L[A[i]]>R[A[i-1]]) F[i]=F[i-1]+1;
			ANS=min(ANS,N-F[i]);
		}
		printf("%d\n",ANS);
	}
}