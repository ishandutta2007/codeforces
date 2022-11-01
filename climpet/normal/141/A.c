#include <stdio.h>
int main(void){
	int t[26] = {0}, i, j;
	char s[120];
	for(i=0;i<2;i++){
		scanf(" %s",s);
		for(j=0;s[j];j++)t[s[j]-'A']++;
	}
	scanf(" %s",s);
	for(i=0;s[i];i++)t[s[i]-'A']--;
	for(i=0;i<26;i++)
		if(t[i]){puts("NO");return 0;}
	puts("YES");return 0;
}