#include <iostream>
#include <cstdio>
using namespace std;

long long read(){
    long long cnt = 0;
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
	int q = read();
	while (q --){
		long long x = read(), y = read(), k = read();
		long long cnt = max(x, y), have = min(x, y);
		if (cnt > k)
			printf("-1\n");
		else{
			if ((cnt - have) % 2 == 0){
				if ((k - cnt) % 2 == 1)
					cout << k - 2 << endl;
				else
					cout << k << endl;
			}
			else
				cout << k - 1 << endl;
		}
	}
}