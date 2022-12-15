#include<bits/stdc++.h>
using namespace std;

int N;
int A[100005],id[100005];
int ans[100005];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),id[i]=i;
	int clk0=clock();
	while(clock()-clk0<CLOCKS_PER_SEC*0.45){
		random_shuffle(id+1,id+N+1);
		int t1=0,t2=0,t11;
		for(int i=1;i<=N;i++)
			if((t11=gcd(t1,A[id[i]]))!=t1)
				t1=t11,ans[id[i]]=1;
			else t2=gcd(t2,A[id[i]]),ans[id[i]]=2;
		if(t1==1&&t2==1){
			printf("YES\n");
			for(int i=1;i<=N;i++) printf("%d ",ans[i]);
			return 0;
		}
	}
	printf("NO\n");
}