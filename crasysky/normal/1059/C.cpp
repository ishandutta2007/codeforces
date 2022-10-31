#include <iostream>
#include <cstdio>
#define maxn 2003
using namespace std;
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read();
	int have = 1;
	while (n){
		if (n != 3)
			for (int i = 1; i <= (n + 1) / 2; ++ i)
				printf("%d ", have);
		else{
			printf("%d %d %d ", have, have, have * 3);
			return 0;
		}
		have *= 2;
		n /= 2;
	}
}