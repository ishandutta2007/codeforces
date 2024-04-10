#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
int x[3];
int main(){
	int i,j;
	cin>>n;
	while(n--){
		cin>>x[0]>>x[1]>>x[2];
		sort(x,x+3);
		if(x[2]>x[0]+x[1]){
			cout<<x[0]+x[1]<<endl;
		}
		else{
			cout<<(x[0]+x[1]+x[2])/2<<endl;
		}
	}
	return 0;
}