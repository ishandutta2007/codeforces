#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#define maxn 100009
using namespace std;
int ans[maxn],tot,p[maxn],flag[maxn];
void init(){
	for(int i = 2; i< maxn; i++){
		if(!flag[i])
			p[tot++] = i;
		for(int j = 0; j < tot && 1LL * i * p[j] < maxn; j++){
			flag[i * p[j]] = 1;
			if(i % p[j] == 0)
				break;
		}
	}
}
int main(){
	init();
	int tot = 1;
	int n;
	cin >> n;
	for(int i = 2 ;i <= n + 1;i ++){
		if(flag[i] == 0)
			ans[i] = 1;
		else{
			tot = 2;
			ans[i] = 2;
		}
	}
	cout << tot << endl;
	for(int i = 2 ;i <= n + 1; i++)
		cout << ans[i] << " ";
	return 0;
}