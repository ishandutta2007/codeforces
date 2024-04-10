#include <cstdio>
#include <cstring>

using namespace std;

char C[1010101];
int Mod = 1e9+7;
int n,i,ans,k;

int main()
{
	scanf("%s",C);

	n = strlen(C);

	for(i=n-1;i>=0;i--){
		if(C[i] == 'a'){
			ans = (ans+k) % Mod;
			k = (k+k) % Mod;
		}
		else{
			k = (k+1) % Mod;
		}
	}

	printf("%d\n",ans);

	return 0;
}