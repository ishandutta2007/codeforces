#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int ans[1080][1080], n, k, d;


int main(){
	cin >> n >> k >> d;
	
	for(int i = 0;i < n;i++){
		int num = i;
		for(int j = 0;j < d;j++){
			ans[i][j] = num % k;
			num /= k;
		}
	}
	for(int i = 1;i < n;i++){
		int allzero = 1;
		for(int j = 0;j < d;j++){
			if(ans[i][j])allzero = 0;
		}
		if(allzero){
			cout << -1 << endl;
			return 0;
		}
	}
	
	for(int i = 0;i < d;i++){
		for(int j = 0;j < n;j++){
			if(j)printf(" ");
			printf("%d", ans[j][i] + 1);
		}puts("");
	}
	return 0;	
	
}