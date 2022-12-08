#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
int kk;
int tot,num1,num2,cnt,n;
bool check[MAXN];
int prime[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=2;i<=400000;++i){
		if (!check[i]){
			prime[++tot]=i;
		}
		for (int j=1;j<=tot;++j){
			if (i*prime[j]>400000) break;
			check[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	for (int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		if (x==1) ++num1; else ++num2;
	}
	int now=0,top=0; int k=0;
	while (1){
		++top;
		if (now+num1+num2*2<prime[top]){
			for (int i=1;i<=num1;++i) printf("1 ");
			for (int i=1;i<=num2;++i) printf("2 ");
			exit(0);
		}
		while (num2>0&&prime[top]-now>=2){
			printf("2 "); now+=2; --num2;
		} 
		while (num1>0&&prime[top]-now>=1){
			printf("1 "); now+=1; --num1;
		}
	}
}