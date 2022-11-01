#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int a[55]={0},cnt=0,n;
	cin>>n;
	while(n--){
		cin>>a[cnt];
		for(int j=0;j<cnt;j++){
			if(a[j]==a[cnt]){
				a[j]=0;
				cnt--;
				for(int i=j;i<=cnt;i++){
					a[i]=a[i+1];
				}
			}
		}
		cnt++;
	}
	cout<<cnt<<endl;
	for(int j=0;j<cnt;j++){
		cout<<a[j]<<' ';
	}
	return 0;
}