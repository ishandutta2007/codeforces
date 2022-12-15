#include<bits/stdc++.h>
using namespace std;

int N;
int A[200005];

int P[31],cnt;
void Insert(int x){
	for(int i=30;~i;i--) if((x>>i)&1){
		if(!P[i]) P[i]=x,cnt++;
		x^=P[i];
	}
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),A[i]^=A[i-1],Insert(A[i]);
	if(A[N]==0) printf("-1\n");
	else printf("%d\n",cnt); 
}