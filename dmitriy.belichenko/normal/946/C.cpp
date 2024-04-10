#include <stdio.h>
#include <iostream>
using namespace std;
int main() 
{
	int t, i, c; char s[100100];
	for (cin >> s, t = c = i = 0; c != 26 && s[i]; i++)
		s[i] <= 'a'+t && (s[i] = 'a'+t, c++, t++);
	puts(c == 26 ? s : "-1");
        return 0;
}