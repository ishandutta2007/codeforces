#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

LL A[2][2], B[2][2]={{0,2},{1,1}}, C[2][2];

vector <LL> bi;
LL Mod=1e9+7;

void f(LL a)
{
	bi.clear();
	
	int i,j,k;
	
	while(a) bi.push_back(a%2), a/=2;
	
	while(bi.size()){
		C[0][0] = (B[0][0]*B[0][0] + B[0][1]*B[1][0])%Mod;
		C[0][1] = (B[0][0]*B[0][1] + B[0][1]*B[1][1])%Mod;
		C[1][0] = (B[1][0]*B[0][0] + B[1][1]*B[1][0])%Mod;
		C[1][1] = (B[1][0]*B[0][1] + B[1][1]*B[1][1])%Mod;
		B[0][0] = C[0][0]; B[0][1] = C[0][1]; B[1][0] = C[1][0]; B[1][1] = C[1][1];
		
		if(bi.back() == 1){
			C[0][0] = (B[0][0]*A[0][0] + B[0][1]*A[1][0])%Mod;
			C[0][1] = (B[0][0]*A[0][1] + B[0][1]*A[1][1])%Mod;
			C[1][0] = (B[1][0]*A[0][0] + B[1][1]*A[1][0])%Mod;
			C[1][1] = (B[1][0]*A[0][1] + B[1][1]*A[1][1])%Mod;
			B[0][0] = C[0][0]; B[0][1] = C[0][1]; B[1][0] = C[1][0]; B[1][1] = C[1][1];
		}
		
		bi.pop_back();
	}
	
	return;
}

int main()
{
	LL a;
	int i,k;
	
	scanf("%d",&k);
	
	for(i=0;i<k;i++){
		A[0][0] = B[0][0]; A[0][1] = B[0][1]; A[1][0] = B[1][0]; A[1][1] = B[1][1];
		B[0][0] = 1; B[0][1] = 0; B[1][0] = 0; B[1][1] = 1;
		scanf("%I64d",&a);
		f(a);
	}
	
	printf("%I64d/%I64d\n",(B[0][0]+(B[0][0]%2)*Mod)/2%Mod,(B[0][0]+B[0][1]+((B[0][0]+B[0][1])%2)*Mod)/2%Mod);
	
	return 0;
}