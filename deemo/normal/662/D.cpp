#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

char ch[200];
string s;

int main(){
	int te;	scanf("%d", &te);
	while (te--){
		scanf("%s", ch);	s = ch;
		s = s.substr(4);
		int zz = 1, sm = 0;
		for (int i = 0; i < s.size(); i++, zz *= 10)
			if (zz - 1)	sm += zz;
		int ans = 1989 + sm;
		int y = 1;
		for (int i = (int)s.size() - 1; i >= 0; i--, y *= 10){
			int dig = ans%(10*y)/y;
			while (dig != s[i] - '0')	
				dig = (dig + 1) % 10, ans += y;
		}
		printf("%d\n", ans);
	}
	return 0;
}