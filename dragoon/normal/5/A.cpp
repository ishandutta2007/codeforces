#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;


int main()
{
    char line[1000];
    int cnt=0, ans=0,i;

    while(gets(line))
    {
        if(line[0]=='+')
        {
            cnt++;
        }
        else if(line[0]=='-')
        {
            cnt--;
        }
        else
        {
            for(i=0;line[i]!=':';i++);
            ans+=cnt*(strlen(line)-i-1);
        }
    }

    printf("%d\n",ans);

    return 0;
}