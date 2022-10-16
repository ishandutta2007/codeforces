#include<bits/stdc++.h>
using namespace std;
int a[1000031][26];
char s[1000031],t[1000031];
int main()
{
    scanf("%s",s);
    scanf("%s",t);
    int n=strlen(s),m=strlen(t);
    for(int i=0;i<26;i++)a[n][i]=n;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<26;j++)
            a[i][j]=a[i+1][j];
        a[i][s[i]-'a']=i;
    }
    int r=1,j=-1;
    for(int i=0;i<m;i++)
    {
        j=a[j+1][t[i]-'a'];
        if(j==n)
        {
            j=a[0][t[i]-'a'];
            r++;
            if(j==n)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<r;
}