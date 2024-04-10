#include<bits/stdc++.h>

using namespace std;

const int maxn=2005;

int n,p;
int x[maxn];
int prd[maxn][maxn];
int o[maxn];
char tmp[maxn];

int main(){
	cin>>n>>p>>tmp;
	for(int i=0;i<n;i++){
		if(tmp[i]=='0') x[i]=0;
		if(tmp[i]=='1') x[i]=1;
		if(tmp[i]=='.') x[i]=-1;
	}
	for(int i=0;i<n;i++){
		prd[i%p][i/p]=x[i];
		prd[i%p][i/p+1]=-4;
	}
	bool np=1;
	for(int i=0;i<p;i++){
		int j=0;
		bool y0=0,y1=0,ye=0;
		while(prd[i][j]!=-4){
			if(prd[i][j]==0) y0=1;
			if(prd[i][j]==1) y1=1;
			if(prd[i][j]==-1) ye=1;
			j++;
		}
		if(y0&&y1){
			np=0;
			int j=i;
			while(j<n){
				o[j]=0;
				j+=p;
			}
		}
		if(y0&&ye){
			np=0;
			int j=i;
			while(j<n){
				o[j]=1;
				j+=p;
			}
		}
		if(y1&&ye){
			np=0;
			int j=i;
			while(j<n){
				o[j]=0;
				j+=p;
			}
		}
		if(ye&&(!y0)&&(!y1)){
			if(n<=i+p)continue;
			np=0;
			int j=i+p;
			o[i]=1;
			while(j<n){
				o[j]=0;
				j+=p;
			}
		}
	}
	if(np) cout<<"No";
	else{
		for(int i=0;i<n;i++){
			if(x[i]==-1) cout<<o[i]; 
			else cout<<x[i];
		}
	}
	return 0;
}