#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector<int> _3;
void mian(){
	cin>>n;
	_3.clear();
	for(int i=50000;i>=2;i--)while(n>=1ll*i*(i-1)/2)n-=1ll*i*(i-1)/2,_3.pb(i);
	cout<<1;
	_3.pb(0);//
	for(int i=_3.size()-2;~i;i--){
		for(int j=1;j<=_3[i]-_3[i+1];j++)cout<<3;
		cout<<7;
	}
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
/*1
2
6
1
*/