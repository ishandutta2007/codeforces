#include <bits/stdc++.h>
using namespace std;
int gr[305][305];
int main() {
	int n;
	cin>>n;
	if(n==1){
		int x;
		cin>>x;
		if(x==0){
			cout<<"BitAryo";
			return 0;
		}
		else{
			cout<<"BitLGM";
			return 0;
		}
	}
	if(n==2){
		int x, y;
		cin>>x>>y;
		gr[0][0]=0;
		
		for(int i=0; i<=300; i++){
			for(int j=0; j<=300; j++){
				if(i==0 && j==0){
					continue;
				}
				bool a[901];
				for(int k=0; k<901; k++){
					a[k]=0;
				}
				set<int>s;
				for(int k=1; k<=i; k++){
					a[gr[i-k][j]]=1;
				}
				for(int k=1; k<=j; k++){
					a[gr[i][j-k]]=1;
				}
				for(int k=1; k<=min(i,j); k++){
					a[gr[i-k][j-k]]=1;
				}
				
				for(int k=0; k<=900; k++){
					if(a[k]==0){
						gr[i][j]=k;
						break;
					}
				}
			}
			
		}
		
		if(gr[x][y]==0){
			cout<<"BitAryo";
		return 0;
		}
		else{
			cout<<"BitLGM";
			return 0;	
		}
	}
	if(n==3){
		
		int x, y, z;
		cin>>x>>y>>z;
		if((x^y^z)==0){
			cout<<"BitAryo";
		return 0;
		}
		else{
			cout<<"BitLGM";
			return 0;
		}
	}
	return 0;
}