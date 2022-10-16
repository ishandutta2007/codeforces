#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[100005];
int book[200005];
int main(){
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]>ans){
			cout<<i<<endl;
			return 0;
		}
		if (ans<=200000)book[a[i]]++;
		while(book[ans]==1)ans++;
	}
	cout<<-1<<endl;
	return 0;
}