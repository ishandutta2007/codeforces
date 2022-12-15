#include<bits/stdc++.h>
using namespace std;

int N,K;
int P[105],Q[105],S[105],invQ[105];
int tmpP[105];

int main(){
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++) scanf("%d",&Q[i]),invQ[Q[i]]=i,P[i]=i;
	bool flg=1;
	for(int i=1;i<=N;i++) scanf("%d",&S[i]),flg&=(S[i]==i);
	if(flg){printf("NO\n");return 0;}
	flg=1;
	for(int i=1;i<=N;i++) flg&=(Q[i]==invQ[i]);
	if(flg){
		for(int i=1;i<=N;i++) flg&=(Q[i]==S[i]);
		if(flg&&K==1) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	for(int i=1;i<=K;i++){
		for(int j=1;j<=N;j++) tmpP[Q[j]]=P[j];
		for(int j=1;j<=N;j++) P[j]=tmpP[j];
		flg=1;
		for(int j=1;j<=N;j++) flg&=(P[j]==S[j]);
		if(flg){
			if((K-i)%2==0){printf("YES\n");return 0;}
		}
	}
	for(int j=1;j<=N;j++) P[j]=j;
	for(int i=1;i<=K;i++){
		for(int j=1;j<=N;j++) tmpP[invQ[j]]=P[j];
		for(int j=1;j<=N;j++) P[j]=tmpP[j];
		flg=1;
		for(int j=1;j<=N;j++) flg&=(P[j]==S[j]);
		if(flg){
			if((K-i)%2==0){printf("YES\n");return 0;}
		}
	}
	printf("NO\n");
}