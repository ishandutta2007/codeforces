#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

LL D[101], Mod=1e9+7;
LL K[101][101],R[101][101],C[101][101];

vector <int> bk;
LL n,k,i,j,l,a,c;

int main()
{
	scanf("%I64d %I64d",&n,&k);
	
	for(i=0;i<n;i++) scanf("%I64d",&D[i]);
	
	for(i=0;i<n;i++)for(j=0;j<n;j++) if(__builtin_popcountll(D[i]^D[j])%3==0) K[i][j]=1;
	for(i=0;i<n;i++) R[i][i]=1;
	
	k--;
	while(k) bk.push_back(k%2), k/=2; 
	
	while(bk.size()){
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			C[i][j]=0;
			for(l=0;l<n;l++) C[i][j] = (C[i][j]+R[i][l]*R[l][j])%Mod;
		}
		for(i=0;i<n;i++) for(j=0;j<n;j++) R[i][j] = C[i][j];
		
		if(bk.back()==1){
			for(i=0;i<n;i++) for(j=0;j<n;j++){
				C[i][j]=0;
				for(l=0;l<n;l++) C[i][j] = (C[i][j]+R[i][l]*K[l][j])%Mod;
			}
			for(i=0;i<n;i++) for(j=0;j<n;j++) R[i][j] = C[i][j];
		}
		
		bk.pop_back();
	}
	
	LL ans=0;
	for(i=0;i<n;i++) for(j=0;j<n;j++) ans = (ans+R[i][j])%Mod;
	
	printf("%I64d\n",ans);
	
	return 0;
}