#include<bits/stdc++.h>
using namespace std;
int x[102][102],H,W,p,maxn=1e9;
int main(){
	cin>>H>>W;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			char c;cin>>c;
			if(c=='B'){x[i][j]=1;p++;}
		}
	}
	for(int i=1;i<=H;i++){for(int j=1;j<=W;j++){x[i][j]+=x[i][j-1];}}
	for(int i=1;i<=H;i++){for(int j=1;j<=W;j++){x[i][j]+=x[i-1][j];}}
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			for(int k=i;k<=H;k++){
				for(int l=j;l<=W;l++){
					if(l-j!=k-i)continue;
					int pos=x[i-1][j-1]+x[k][l]-x[i-1][l]-x[k][j-1];
					if(pos==p){
						maxn=min(maxn,(k-i+1)*(l-j+1)-p);
					}
				}
			}
		}
	}
	if(maxn>=1e8)maxn=-1;
	cout<<maxn<<endl;
	return 0;
}