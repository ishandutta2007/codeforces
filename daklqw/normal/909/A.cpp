#include <stdio.h>
#include <string.h>
char str1[20], str2[20];
int len1, len2, pos1, pos2;
int main() {
	scanf("%s%s", str1, str2);
	len1 = strlen(str1), len2 = strlen(str2);
	putchar(str1[0]);
	for (int i = 1; i < len1 && str1[i] < str2[0]; i++)
		putchar(str1[i]);
	putchar(str2[0]); puts("");
	return 0;
}