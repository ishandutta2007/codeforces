#include<bits/stdc++.h>

using namespace std;

const int maxn=505;
const int dx[5]={-1,-1,1,1};
const int dy[5]={-1,1,-1,1};

char x[maxn][maxn];
int n;
int cnt;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>(x[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char cur='X';
			bool ok=1;
			if(x[i][j]!=cur)ok=0;
			for(int k=0;k<4;k++){
				if(x[i+dx[k]][j+dy[k]]!=cur)ok=0;
			}
			if(ok) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}