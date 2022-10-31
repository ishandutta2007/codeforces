#include<bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
int n,ti,sum,t;
int main(){
	cin>>n>>t;
	for (int i=0;i<n;i++){
		cin>>ti;
		ti = 86400-ti;
		sum+=ti;
		if (sum>=t){
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}