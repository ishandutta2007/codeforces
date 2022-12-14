#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
#define N 1005
char str[N], ok[N];
int main(){
	ok[1] = 'C';
	ok[2] = 'O';
	ok[3] = 'D';
	ok[4] = 'E';
	ok[5] = 'F';
	ok[6] = 'O';
	ok[7] = 'R';
	ok[8] = 'C';
	ok[9] = 'E';
	ok[10] = 'S';
	scanf("%s", str + 1);
	int cnt = 0, n = strlen(str + 1), l = 10, r = 10;
	if(n < 10){
		printf("NO\n");
		return 0;
	}
	for(int i = 1;i <= 10;i ++) if(str[i] != ok[i]){ l = i - 1; break;}
	for(int i = 1;i <= 10;i ++) if(str[n - i + 1] != ok[10 - i + 1]){ r = i - 1; break;}
	printf("%s\n", (l + r >= 10) ? "YES" : "NO");
	return 0;
}