#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
long long a[26][26];
int main(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		for(R j=1;j<=n;j++){
			if((i&1)==0){
				a[i][j]=0;
			}else{
				a[i][j]=1ll<<i+j;
			}
			printf("%lld ",a[i][j]);
		}
		puts("");
	}
	fflush(stdout);
	int q;
	scanf("%d",&q);
	for(R i=0;i!=q;i++){
		long long x;
		scanf("%lld",&x);
		x^=a[n][n];
		vector<int>A,B;
		A.push_back(n);
		B.push_back(n);
		int posx=n,posy=n;
		while(posx!=1||posy!=1){
			if((posx&1)==1){
				if(posy==1){
					posx--;
				}else if((x&a[posx][posy-1])==a[posx][posy-1]){
					posy--;
					x^=a[posx][posy];
				}else{
					posx--;
				}
			}else{
				if(posx==1){
					posy--;
				}else if((x&a[posx-1][posy])==a[posx-1][posy]){
					posx--;
					x^=a[posx][posy];
				}else{
					posy--;
				}
			}
			A.push_back(posx);
			B.push_back(posy);
		}
		int l=A.size();
		for(R i=l-1;i!=-1;i--){
			printf("%d %d\n",A[i],B[i]);
		}
		fflush(stdout);
	}
	return 0;
}