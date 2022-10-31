#include<bits/stdc++.h>
using namespace std;
int v1,v2,t1,t2,n;
long long ans1,ans2;
int main(){
	scanf("%d%d%d%d%d",&n,&v1,&v2,&t1,&t2);
	ans1 = 2*t1+n*v1;
	ans2 = 2*t2+n*v2;
	if (ans1==ans2){
		cout<<"Friendship"<<endl;
	}else{
		if (ans1>ans2){
			cout<<"Second"<<endl;
		}else{
			cout<<"First"<<endl;
		}
	}
	return 0;
}