#include<bits/stdc++.h>
using namespace std;
int sg[100010];
int main()
{
	int n;
	int st=0;
	cin>>n;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=i+1;j++){
			sg[++st]=i;
		}
	}
	int ans=0;
	while(n--){
		cin>>st;//1<=st<=60
		ans^=sg[st];
	}
	if(ans==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}