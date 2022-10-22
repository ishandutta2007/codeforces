#include<iostream>
#include<algorithm>

using namespace std;

bool notp[1080000];

int main(){
	int n;
	cin >> n;
	for(int i = 2;i * i <= n;i++){
		if(notp[i] == true)continue;
		for(int j = i * i;j <= n;j += i){
			notp[j] = true;
		}
	}
	
	for(int i = 4;i <= n;i++){
		if(notp[i] && notp[n - i]){
			cout << i << " " << n - i<< endl;
			return 0;
		}
	}
	
}