#include<bits/stdc++.h>
using namespace std;
int a[49][49],n,cnt;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int dst=abs((n/2)-i);dst=(n/2)-dst;
		for(int j=(n/2)-dst;j<=(n/2)+dst;j++){
			a[i][j]=cnt*2+1;cnt++;
		}
	}
	int cnt=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j)cout<<' ';
			if(a[i][j]==0){a[i][j]=cnt*2;cnt++;}
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}