#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

char s[N];
bool h = false, e = false, i_1 = false, d = false, i_2 = false;
int main (int argc, char *argv[])
{
	scanf("%s", &s);
	for(int i = 0; s[i]; ++i) {
		if(s[i] == 'h') {
			h = true;
		} else if(s[i] == 'e' && h) {
			e = true;
		} else if(s[i] == 'i') {
			if(d) {
				i_2 = true;
			} else if(e) {
				i_1 = true;
			}
		} else if(s[i] == 'd' && i_1) {
			d = true;
		}
	}
	if(h && e && i_1 && d && i_2) {
		printf("YES");
	} else {
		printf("NO");	
	}

	return 0;
}