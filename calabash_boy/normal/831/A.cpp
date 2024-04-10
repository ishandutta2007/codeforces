#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int n;
int num[MAXN];
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num[i];
	}
	int ans1 = 0;
	while (ans1<n-1&&num[ans1]<num[ans1+1]){
		ans1++;
	}
	if (ans1==n-1){
		cout<<"YES"<<endl;
		return 0;
	}
	int ans2 = n-1;
	while (ans2>0&&num[ans2-1]>num[ans2]){
		ans2--;
	}
//	cout<<ans1<<" "<<ans2<<endl;
	int flag = num[ans2];
	for (int i=ans1;i<=ans2;i++){
		if (num[i]!=flag){
			cout<<"NO"<<endl;
			return 0;
		}
	} 
	cout<<"YES"<<endl;
	return 0;
}