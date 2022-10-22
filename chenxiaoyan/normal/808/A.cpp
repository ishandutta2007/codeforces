/*








*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> luc;
void luc_init(){
	int now=1;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=9;j++)luc.pb(j*now);
		now*=10;
	}
}
int main(){
	luc_init();
	int x;
	cin>>x;
	for(int i=0;;i++)if(luc[i]>x)return cout<<luc[i]-x,0;
	return 0;
}