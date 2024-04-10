#include <bits/stdc++.h>
using namespace std;
int t, n, a[110];
int main()
{
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		int ret = -1;
		for (register int i = 1;i <= n;i ++){
			scanf("%d", &a[i]);
			ret = max(a[i], ret);
		}
		string s;
		ret ++;
		for (register int i = 1;i <= ret;i ++) s += 'a';
		cout << s << '\n';
		for (register int i = 1;i <= n;i ++){
			for (register int j = 0;j < a[i];j ++){
				putchar(s[j]);
			}
			for (register int j = a[i];j < ret;j ++){
				if(s[j] == 'a') {
					putchar(s[j] = 'b');
				}
				else{
					putchar(s[j] = 'a');
				}
			}
			putchar(10);
		}
	} 
}