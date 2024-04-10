#include <iostream>
#include <fstream>
#define MAXN 101
typedef long long LL;
using namespace std;

LL r1,r2;
LL ff[MAXN][31];
string A,B;

int main(){
	cin >> r1 >> r2;
	cin >> A >> B;
	LL N=A.size();
	LL M=B.size();
	for(int i=0;i<N;i++){
		int it=0;
		for(int j=0;j<10000;j++){
			if(it==M){
				ff[i][0]=j;
				break;
			}
			if(B[it]==A[(i+j)%N])it++;
		}
		if(ff[i][0]==0){
			cout << 0 << "\n";
			return 0;
		}
	}
	for(int i=1;i<=30;i++)for(LL j=0;j<N;j++){
		ff[j][i]=ff[j][i-1]+ff[(j+ff[j][i-1])%N][i-1];
	}
	LL it=0;
	LL res=0;
	LL sum=r1*N;
	for(LL i=30;i>=0;i--){
		if(ff[it][i]<=sum){
			res+=1ll<<i;
			sum-=ff[it][i];
			it=(it+ff[it][i])%N;
		}
	}
	cout << res/r2 << "\n";
}