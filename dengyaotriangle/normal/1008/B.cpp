#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
int x[maxn][2];

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i][0]>>x[i][1];
	int ph=2147483645;
	for(int i=0;i<n;i++){
		if(!(x[i][0]>=x[i][1])) swap(x[i][0],x[i][1]);
		if(x[i][1]>ph){
			cout<<"NO";
			return 0;
		}
		if(x[i][0]>ph){
			ph=x[i][1];
		}else{
			ph=x[i][0];
		}
	}
	cout<<"YES";
	return 0;
}