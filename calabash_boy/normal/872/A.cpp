#include<bits/stdc++.h>
using namespace std;
bool has1[15],has2[15];
int ans;
int m,n;
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		has1[x] =true;
	}
	for (int i=0;i<m;i++){
		int x;
		cin>>x;
		has2[x]=true;
	}
	while (true){
		bool flag1=false,flag2=false;
		int temp=ans;
		while (temp){
			int x = temp%10;
			if (has1[x]){
				flag1=true;
			}
			if (has2[x]){
				flag2=true;
			}
			temp/=10;
		}
		if (flag1&&flag2){
			cout<<ans<<endl;
			return 0;
		}
		ans++;
	}
	return 0;
}