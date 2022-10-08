/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

char s[100001];

int main() {
	gets(s);
	int i = 0;
	while (s[i] && s[i] == 'a')
		i++;
	if (!s[i]) 
		s[i - 1] = 'z';
	while (s[i] && s[i] != 'a')
		s[i++]--;
	puts(s);
}