#include<bits/stdc++.h>
using namespace std;

int N;
int A[60];
bool cmp(int a,int b){
	return a>b;
}
int SumA;
bool F[30][1250005];int fa[30][1250005];
bool used[60];
int ANS[2][30];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=2*N;i++) scanf("%d",&A[i]);
	sort(A+1,A+2*N+1,cmp);
	N=2*N-2;
	for(int i=1;i<=N;i++) SumA+=A[i];SumA/=2;
	F[0][0]=1;
	for(int i=1;i<=N;i++)
	for(int j=min(i,N/2);j>=0;j--)
	for(int k=SumA;k>=0;k--)
		if(j>=1&&k>=A[i]&&F[j-1][k-A[i]]&&!F[j][k]) F[j][k]=1,fa[j][k]=i;
	int x=-1;
	for(int k=SumA;k>=0;k--)
		if(F[N/2][k]){x=k;break;}
	for(int i=N/2;i;i--){
		ANS[0][i]=fa[i][x];used[fa[i][x]]=1;
		x-=A[fa[i][x]];
	}
	printf("%d ",A[N+1]);for(int i=N/2;i;i--) printf("%d ",A[ANS[0][i]]);printf("\n");
	for(int i=1;i<=N;i++) if(!used[i]) printf("%d ",A[i]);printf("%d\n",A[N+2]);
}