#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define L long long
vector<int>A[13];
L S[13],ans[1000];
int m[1717];
inline int Size(int x){
	int s=0;
	while(x!=0){
		s++;
		x-=x&-x;
	}
	return s;
}
int main(){
	int n,ct=0;
	scanf("%d",&n);
	for(R i=1;i!=8192;i++){
		if(Size(i)==6){
			m[ct]=i;
			for(R j=0;j!=13;j++){
				if((i>>j&1)==0){
					A[j].push_back(ct);
				}
			}
			ct++;
			if(ct==n){
				break;
			}
		}
	}
	for(R i=0;i!=13;i++){
		if(A[i].empty()==false){
			printf("? %d",A[i].size());
			for(vector<int>::iterator T=A[i].begin();T!=A[i].end();T++){
				printf(" %d",*T+1);
			}
			puts("");
			fflush(stdout);
			scanf("%lld",S+i);
		}
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=13;j++){
			if((m[i]>>j&1)==1){
				ans[i]|=S[j];
			}
		}
	}
	putchar('!');
	for(R i=0;i!=n;i++){
		printf(" %lld",ans[i]);
	}
	return 0;
}