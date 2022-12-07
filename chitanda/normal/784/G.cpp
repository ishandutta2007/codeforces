#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
	cin >> s;
	int n = s.size();
	int now = 0;
	int i = 0;
	int pre_c = 0;
	int ans = 0;
	for(; i < n; ++i){
		if(s[i] == '+' || s[i] == '-'){
			if(pre_c == 0) ans += now;
			else ans -= now;
			pre_c = s[i] == '-';
			now = 0;
		}else now = now * 10 + s[i] - '0';
	}
	if(pre_c == 0) ans += now;
	else ans -= now;
	if(ans == 0){
		printf("++++++++++++++++++++++++++++++++++++++++++++++++.\n");
		return 0;
	}
	bool flag = 0;
	if(ans / 100){
		int x = ans / 100;
		for(int i = 0; i < x; ++i) printf("+"); printf("\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++.\n");
		printf(">");
		ans %= 100;
		flag = 1;
	}
	if((ans / 10) || flag){
		int x = ans / 10;
		for(int i = 0; i < x; ++i) printf("+"); printf("\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++.\n");
		printf(">\n");
		ans %= 10;
	}
	int x = ans;
	for(int i = 0; i < x; ++i) printf("+"); printf("\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++.\n");
	ans %= 10;
	return 0;
}