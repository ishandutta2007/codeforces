/******************
*  Writer: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int n,a[15];
int k,sum;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;k=n-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n==1){
		cout<<"-1";
		return 0;
	}
	
	for(int k=1;k<=n;k++){
		sum=0;
		for(int i=1;i<=n;i++){
			if(i==k){
				continue;
			}
			sum+=a[i];
		}
		if(sum!=a[k]){
			cout<<1<<endl;
			cout<<k;
			return 0;
		}
	}
	
	cout<<-1;
	
	return 0;
}