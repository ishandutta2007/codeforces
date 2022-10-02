#include <iostream>
#define MAXN 5010
using namespace std;

int N,M;
int p[MAXN];
int din[MAXN][MAXN];
int s[MAXN][MAXN];

int main(){
	cin >> N >> M;
	double pstr;
	for(int i=0;i<N;i++) cin >> p[i] >> pstr;
	
	for(int j=1;j<=M;j++) for(int i=N-1;i>=0;i--) s[j][i] = s[j][i+1] + ( (p[i]>=j)?1:0 );
	
	for(int k=N-2;k>=0;k--) for(int t=M-1;t>=1;t--){
		if( p[k]<t or s[p[k]][k]==s[t][k] ) din[k][t]=din[k+1][t];
		else din[k][t]=min( 1+din[k+1][t] , (s[t][k]-s[p[k]][k])+din[k+1][p[k]] );
	}
	cout << din[0][1] << "\n";
}