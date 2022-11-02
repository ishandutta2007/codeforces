#include <bits/stdc++.h>
#define maxn 100009
using namespace std;
char s[maxn];
int main(){
	int n, a, b;
	cin >> n >> a >> b;
	scanf("%s", s + 1);
	if(s[a] == s[b])
		puts("0");
	else{
	 	puts("1");
	}
	//system("pause");
	return 0;
}