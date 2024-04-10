#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int T,N,A[100005];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%d",&A[i]);
		bool flg=0;
		for(int i=31;i>=0;i--){
			int cnt=0;
			for(int j=1;j<=N;j++)
				if((A[j]>>i)&1) cnt++;
			if(cnt%4==3&&N%2==1){printf("LOSE\n");flg=1;break;}
			if(cnt%2==1){printf("WIN\n");flg=1;break;}
		}
		if(!flg) printf("DRAW\n");
	}
	return 0;
}