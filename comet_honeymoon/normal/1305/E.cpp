#include<bits/stdc++.h>
using namespace std;

int N,M;
int A[5005];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		A[i]=i;
		M-=(i-1)/2;
		if(M<=0){
			A[i]-=2*M;
			int x=1e9;
			for(int j=N;j>i;j--)
				A[j]=(x-=(A[i]+1));
			for(int j=1;j<=N;j++) printf("%d ",A[j]);
			return 0;
		}
	}
	printf("-1\n"); 
}