#include<iostream>
using namespace std;
int main(){
	int n,a,b;
	int color1,color2;
	cin>>n>>a>>b;
	for (int i=1;i<=n;i++){
		char tmp;
		cin>>tmp;
		if (i==a) color1=tmp;
		if (i==b) color2=tmp;
	}
	if (color1==color2) cout<<0;
	else cout<<1;
	return 0;
}