#include<bits/stdc++.h>
using namespace std;

const int maxN=100005,len=350;
int F[maxN][len+5];

int N,Q;
int A[maxN];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	for(int i=1;i<=len;i++)
	for(int j=N;j;j--)
		if(j+A[j]+i>N) F[j][i]=1;
		else F[j][i]=F[j+A[j]+i][i]+1;
	scanf("%d",&Q);
	while(Q--){
		int p,k;scanf("%d%d",&p,&k);
		if(k<=len) printf("%d\n",F[p][k]);
		else{
			int ans=0;
			while(p<=N) p+=A[p]+k,ans++;
			printf("%d\n",ans);
		}
	}
}