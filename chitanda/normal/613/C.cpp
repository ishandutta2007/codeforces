#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, a[26], g;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i), g = gcd(g, a[i]);
	if (g & 1){
		int ji = 0, ch;
		for(int i = 0; i < n; i++)
			if ((a[i] / g) & 1) ji++, ch = i;
		if (ji > 1){
			printf("0\n");
			for(int i = 0; i < n; i++)
				for(int j = 1; j <= a[i]; j++)
					printf("%c", 'a' + i);
		}else{
			printf("%d\n", g);
			for(int i = 1; i <= g; i++){
				for(int j = 0; j < n; j++)
					for(int k = 1; k <= a[j] / g / 2; k++)
						printf("%c", 'a' + j);
				printf("%c", 'a' + ch);
				for(int j = n - 1; j >= 0; j--)
					for(int k = 1; k <= a[j] / g / 2; k++)
						printf("%c", 'a' + j);
			}
		}
	}else{
		printf("%d\n", g);
		for(int i = 1; i <= g; i++){
			if (i & 1) 
				for(int j = 0; j < n; j++)
					for(int k = 1; k <= a[j] / g; k++)
						printf("%c", 'a' + j);
			else
				for(int j = n - 1; j >= 0; j--)
					for(int k = 1; k <= a[j] / g; k++)
						printf("%c", 'a' + j);
		}
	}
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/