#include <cstdio>
#include <iostream>
#include <string>
 
using namespace std;
 
inline int read(){
    int x = 0; int zf = 1; char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') zf = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}
 
int rd = 0;
int bl = 0;
int ans[200005];
 int aaaa;
int main(){
	int n = read(); int now=111;
	string s; cin >> s;
	for (int i = 0; i < n; ++i){
		if (s[i] == ')')
			(rd > bl) ? (--rd, ans[i] = 0) : (--bl, ans[i] = 1);
		else if (s[i] == '(')
			(rd < bl) ? (++rd, ans[i] = 0) : (++bl, ans[i] = 1);
	}
	for (int i = 0; i < n; ++i)
		printf("%d", ans[i]);
	return 0;
}