#include<bits/stdc++.h>

using namespace std;

const int maxn=150004;

int n;
int a[maxn][2];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}	
	for(int t=0;t<2;t++){
		int cur=a[1][t];
		vector<int> div;
		for(int i=2;i*i<=cur;i++){
			if(cur%i==0){
				while(cur%i==0)cur/=i;
				div.push_back(i);
			}
		}
		if(cur!=1)div.push_back(cur);
		for(int i=0;i<div.size();i++){
			bool ok=1;
			for(int j=2;j<=n;j++){
				if(a[j][0]%div[i]!=0&&a[j][1]%div[i]!=0){
					ok=0;
					break;
				}
			} 
			if(ok){
				cout<<div[i];
				return 0;	
			}
		}
	}
	cout<<-1;
	return 0;
}