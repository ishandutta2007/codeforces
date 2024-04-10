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
	long long n = read(), k = read();
	cout << (k + n - 1) / n << endl;
}