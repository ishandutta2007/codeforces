#include<bits/stdc++.h>
using namespace std;
const int grundy[31]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};
int n;
int w[31],ans;
bool flg[40000];
int main(){
	scanf("%d",&n);
	int M=ceil(sqrt(n)),rem=n-M;
	w[1]=1;
	for(int i=2;i<=M;i++)if(!flg[i]){
		int j=i,cnt=0;
		while(1){
			++cnt;
			if(j<=M)flg[j]=1;
			else rem--;
			if(n/j<i)break;
			j=j*i;
		}
		w[cnt]^=1;
	}
	if(rem&1)w[1]^=1;
	for(int i=1;i<=30;i++)if(w[i])ans^=grundy[i];
	puts(ans?"Vasya":"Petya");
}