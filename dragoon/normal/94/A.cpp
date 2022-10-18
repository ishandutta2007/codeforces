#pragma warning(disable:4786)
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

map<string,int> M;
string L;
char line[100];

int main()
{
    int i;

    scanf("%s",line);
    L = line;

    for(i=0;i<10;i++)
    {
        scanf("%s",line);
        M[ line ] = i;
    }

    for(i=0;i<80;i+=10)
    {
        printf("%d",M[ L.substr(i,10) ] );
    }
    printf("\n");

    return 0;
}