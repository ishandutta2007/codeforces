#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,m,cn[8]={-1,-1,0,1,1,1,0,-1},cm[8]={0,1,1,1,0,-1,-1,-1};
char c[105][105];
int mine(int i,int j){
	int res=0;
	for(int k=0;k<8;k++){
		if(c[i+cn[k]][j+cm[k]]=='*'){
			res++;
		}
	}
	return res;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	bool k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]>='1' && c[i][j]<='9'){
				if(mine(i,j)!=(int)(c[i][j]-'0')){
					k=0;
					break;
				}
			}
			if(c[i][j]=='.'){
				if(mine(i,j)){
					k=0;
					break;
				}
			}
		}
	}
	if(k){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}