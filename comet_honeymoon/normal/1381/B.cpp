#include<bits/stdc++.h>
using namespace std;
 

//???
int T;
int N;
int P[4005],Q[4005]; 
bool vis[4005];
bool F[8005],tmp[8005];
 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=2*N;i++) scanf("%d",&P[i]),Q[P[i]]=i,vis[i]=0;
		int lstpos=2*N+1;
		for(int i=0;i<=4*N;i++) F[i]=0;
		F[2*N]=1;
		for(int i=2*N;i;i--) if(!vis[i]){
			int nowpos=Q[i];
			for(int j=nowpos;j<lstpos;j++) vis[P[j]]=1;
			for(int i=0;i<=4*N;i++){
				tmp[i]=0;
				if(i+lstpos-nowpos<=4*N) tmp[i]|=F[i+lstpos-nowpos];
				if(i-lstpos+nowpos>=0) tmp[i]|=F[i-lstpos+nowpos];
			}
			for(int i=0;i<=4*N;i++) F[i]=tmp[i];
			lstpos=nowpos;
		}
		if(F[2*N]) printf("YES\n");else printf("NO\n");
	}
}