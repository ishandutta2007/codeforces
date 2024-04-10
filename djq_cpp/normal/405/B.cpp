#include <iostream>
using namespace std;
char a[3001];
int main(){
	int n,point=0,res=0;
	bool lt=false,beg=true,lend=true;
	cin>>n;
	cin>>a;
	for(int k=0;k<n;k++){
		if(a[k]=='.'){
			point++;
			continue;
		}
		if(a[k]=='L'&&!beg)res+=(point%2);
		if(a[k]=='R')res+=point;
		point=0;
		beg=false;
		lend=(a[k]=='L');
	}
	if(lend)res+=point;
	cout<<res;
	return 0;
}