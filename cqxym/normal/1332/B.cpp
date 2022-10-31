#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
int g[1001][1001],a[1001],col[1001],p[12]={1,2,3,5,7,11,13,17,19,23,29,31};
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		col[i]=0;
	}
	if(n<12){
		printf("%d\n",n);
		for(R i=1;i<=n;i++){
			printf("%d ",i);
		}
	}else{
		int ct=1;
		vector<int>C;
		for(R i=1;i!=12;i++){
			for(R j=1;j<=n;j++){
				if(col[j]==0&&a[j]%p[i]==0){
					C.push_back(j);
				}
			}
			if(C.size()!=0){
				for(R j=0;j!=C.size();j++){
					col[C[j]]=ct;
				}
				ct++;
				C.clear();
			}
		}
		printf("%d\n",ct-1);
		for(R i=1;i<=n;i++){
			printf("%d ",col[i]);
		}
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}