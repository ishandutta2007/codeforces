#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1<<23
bool A[101][10010];
int B[101][10010];
int res[10010];

int main(){
	int n;
	int m;
	cin >> n >> m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		char x;
		cin >> x;
		if(x=='1')A[i][j]=true;
	}
	for(int r=0;r<n;r++){
		int act=INF;
		for(int c=0;c<2*m;c++){
			if(A[r][c%m])act=0;
			else act++;
			B[r][c%m]=act;
		}
		act=INF;
		for(int c=2*m-1;c>=0;c--){
			if(A[r][c%m])act=0;
			else act++;
			B[r][c%m]=min(B[r][c%m],act);
		}
	}
	for(int r=0;r<n;r++)for(int c=0;c<m;c++)res[c]+=B[r][c];
	int ris=INF;
	for(int c=0;c<m;c++)ris=min(ris,res[c]);
	if(ris==INF)cout << -1;
	else cout << ris;
}