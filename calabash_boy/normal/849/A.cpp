#include<bits/stdc++.h>
using namespace std;
const int MAX = 104;
int a[MAX];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	if (a[1]%2==0||a[n]%2==0){
		cout<<"No"<<endl;
		return 0;
	}
	if (n%2==1){
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}