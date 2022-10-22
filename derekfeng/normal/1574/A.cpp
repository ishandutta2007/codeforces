#include<bits/stdc++.h>
using namespace std;
int t,n;
int C,d[55];
void divset(int x){
	if(C==n)return;
	if(x==n){
		++C;
		d[x]=1;
		int N=0;
		for(int i=0;i<n;i++){
			++N;
			if(d[i+1]){
				for(int j=0;j<N;j++)putchar('(');
				for(int j=0;j<N;j++)putchar(')');
				N=0;
			}
		}
		puts("");
		return;
	}
	if(x==0)d[x]=1,divset(x+1);
	else{
		for(int i=0;i<2;i++){
			d[x]=i;
			divset(x+1);
		}
	}
}
void sol(){
	C=0;
	divset(0);
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		sol();
	}
}