#include<bits/stdc++.h>
using namespace std;

int N;
int A[200005];
int ans[200005];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	for(int i=2;i<=N;i++){
		for(int l=1,r;l<=i-2;l=r+1){
			r=(i-2)/((i-2)/l);
			if(A[(i-2)/l+1]>A[i]) ans[l]++,ans[r+1]--;
		}
		if(A[1]>A[i]) ans[i-1]++;
	} 
	for(int i=1;i<=N-1;i++) ans[i]+=ans[i-1],printf("%d ",ans[i]);
}