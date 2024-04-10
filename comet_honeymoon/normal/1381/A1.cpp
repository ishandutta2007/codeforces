#include<bits/stdc++.h>
using namespace std;
 
int T;
int N;
int A[100005],B[100005];
int h,t;
int len,ans[200005];
int flg,flg2;
 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%1d",&A[i]);
		for(int i=1;i<=N;i++) scanf("%1d",&B[i]);
		len=0;flg=0;flg2=0;
		h=1;t=N;
		for(int i=N;i;i--)
			if(flg2==0){
				if(A[t]^flg==B[i]){t--;continue;}
				if(A[h]^flg==B[i]) ans[++len]=1,ans[++len]=i,flg^=1,h++,flg2^=1;
				else ans[++len]=i,flg^=1,h++,flg2^=1;
			}
			else{
				if(A[h]^flg==B[i]){h++;continue;}
				if(A[t]^flg==B[i]) ans[++len]=1,ans[++len]=i,flg^=1,t--,flg2^=1;
				else ans[++len]=i,flg^=1,t--,flg2^=1;
			}
		printf("%d ",len);
		for(int i=1;i<=len;i++) printf("%d ",ans[i]);printf("\n");
	}
}