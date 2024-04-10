#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
char s[3001];
bool vowel[26];
int main()
{
	vowel['e' - 'a'] = vowel[0] = vowel['i' - 'a'] = vowel['o' - 'a'] = vowel['u' - 'a'] = 1;
	scanf("%s", s);
	int n = strlen(s);
	char a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++)
	{
		a = b, b = c, c = s[i];
		if (a!=0 && !vowel[a - 'a'] && !vowel[b - 'a'] && !vowel[c - 'a'] && !(a == b&&b == c))
		{
			printf(" ");
			a = 0, b = 0, c = s[i];
		}
		printf("%c", s[i]);
	}
}