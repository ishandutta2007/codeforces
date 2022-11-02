#include <bits/stdc++.h>
using namespace std;
char s[100];
int main(){
	int n,k;
	cin >> n;
	int cur = 0;
	while(n--){
		cin>>k;
		scanf("%s",s);
		if(s[0] == 'S'){
			if(cur + k >20000){
				puts("NO");
				return 0;
			}
			cur = cur + k;
		}
		else if(s[0]=='N'){
			if(cur - k < 0){
				puts("NO");
				return 0;
			}
			cur -= k;
		}
		else{
			if(cur == 0 || cur == 20000){
				puts("NO");
				return 0;
			}
		}
	}
	if(cur == 0)
		puts("YES");
	else
		puts("NO");
	//system("pause");
	return 0;
}