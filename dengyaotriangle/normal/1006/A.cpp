#include<bits/stdc++.h>

using namespace std;

const int maxn =1005;

int n;
int x[maxn];

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<n;i++){
		if(x[i]%2==0) x[i]--;
	}
	for(int i=0;i<n;i++) cout<<x[i]<<' ';
	return 0;
}