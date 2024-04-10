#include <bits/stdc++.h> 
char ss[100][100]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
char temp[100000];
int main()
{
    int n;
    scanf("%d",&n); 
    int cnt=0;
    for (int ii=0;ii<n;ii++)
    {
        scanf("%s",temp);
        int len=strlen(temp);
        int flag=1;
        for (int i=0;i<len;i++)
        if (temp[i]<'0'||temp[i]>'9') flag=0;
        if (flag==1)
        {
            int x=0;
            for (int i=0;i<len;i++)
                x=x*10+temp[i]-'0';
            if (x<18) cnt++;
        }
        else
        {
            for (int i=0;i<11;i++)
            {
                if (strcmp(ss[i],temp)==0) cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}