#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int m,n;
char x[maxn][maxn];
char chk[3]={'R','G','B'};

int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++) cin>>x[i];
	for(int i=0;i<6;i++){
		if(m%3!=0) break;
		bool ok=1;
		for(int j=0;j<3;j++){
			for(int k=j*m/3;k<(j+1)*m/3;k++){
				for(int l=0;l<n;l++){
					if(x[k][l]!=chk[j]) ok=0;
				}
			}
		}
		if(ok){
			cout<<"YES";
			return 0;
		}
		next_permutation(chk,chk+3);
	}
	for(int i=0;i<6;i++){
		if(n%3!=0) break;
		bool ok=1;
		for(int j=0;j<3;j++){
			for(int k=j*n/3;k<(j+1)*n/3;k++){
				for(int l=0;l<m;l++){
					if(x[l][k]!=chk[j]) ok=0;
				}
			}
		}
		if(ok){
			cout<<"YES";
			return 0;
		}
		next_permutation(chk,chk+3);
	}
	cout<<"NO";
	return 0;
}