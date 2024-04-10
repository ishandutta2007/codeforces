#include <bits/stdc++.h>
using namespace std;

vector <int> v;
#define PB push_back
int n;
char str[104];

int main(){
	scanf("%d", &n);
	scanf("%s", str + 1);
	for(int i = 1;i <= n;i ++){
		int x = str[i] - '0';
		if(x == 2) v.PB(2);
		else if(x == 3) v.PB(3);
		else if(x == 4) v.PB(3), v.PB(2), v.PB(2);
		else if(x == 5) v.PB(5);
		else if(x == 6) v.PB(5), v.PB(3);
		else if(x == 7) v.PB(7);
		else if(x == 8) v.PB(7), v.PB(2), v.PB(2), v.PB(2);
		else if(x == 9) v.PB(7), v.PB(3), v.PB(3), v.PB(2);
	}
	sort(v.begin(), v.end());
	for(int i = (int)v.size() - 1;~i;i --) putchar(v[i] + '0');
	return 0;
}