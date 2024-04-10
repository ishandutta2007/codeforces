#include<cstdio>
#include<cstring>
using namespace std;
char s[300000];
int main()
{
	scanf("%s",s);
	s[strlen(s)]='%';
	int len=strlen(s);
    for(int i=1;i<len-1;i++)
    	if (s[i-1]==s[i])
    	{
    		char ch;
    		for(ch='a';ch<='z';ch++)
    			if ((ch!=s[i-1]) && (ch!=s[i+1]))
    			{
    				s[i]=ch;
    				break;
    			}
    	}
    for(int i=0;i<len-1;i++) printf("%c",s[i]);
    printf("\n");
    return 0;
}