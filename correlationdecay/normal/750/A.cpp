#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	k = 240 - k;
	int cnt = 0;
	for(int i = 1;i <=n;i++){
		if(k >= 5*i){
			cnt++;
			k-=5*i;
		}
	}
	cout<<cnt<<endl;
	//system("pause");
	return 0;
}