#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c,d;
int main(){
	int maxn=0;
	cin>>a>>b>>c>>d;
	for(int i=0;i<=b;i++){
		int E1=a-i,E2=c,E3=d;
		if(E1<0)continue;
		int ans=i*32+min(E1, min(E2, E3))*256;
		maxn=max(maxn,ans);
	}
	cout<<maxn<<endl;
	return 0;
}