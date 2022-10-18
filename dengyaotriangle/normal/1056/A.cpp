#include<bits/stdc++.h>
using namespace std;

const int maxn=105;

int n;
bool ok[maxn][maxn];
bool init[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int r;
		cin>>r;
		while(r--){
			int tmp;
			cin>>tmp;
			ok[i][tmp]=1;
		}
	}
	for(int i=1;i<=100;i++) init[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=100;j++){
			if(!ok[i][j]) init[j]=0;
		}
	}
	for(int i=1;i<=100;i++) if(init[i]) cout<<i<<' ';
	return 0;
}