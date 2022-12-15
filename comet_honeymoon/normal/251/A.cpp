#include<bits/stdc++.h>
using namespace std;

int N,D,X[100005];
long long ANS;

int main(){
	scanf("%d%d",&N,&D);
	for(int i=1;i<=N;i++) scanf("%d",&X[i]);
	sort(X+1,X+N+1);
	int j=1;
	for(int i=1;i<N;i++){
		while(j+1<=N&&X[j+1]-X[i]<=D) j++;
		int len=j-i-1;
		ANS+=1LL*len*(len+1)/2;
	}
	printf("%lld\n",ANS);
}