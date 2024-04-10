#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int map[500][500];
int main()
{
    int mx,my,sx,sy;
    scanf("%d%d%d%d",&mx,&my,&sx,&sy);
    sx--;
    sy--;
    string s;
    cin>>s;
    int r=mx*my;
    for(int i=0;i<s.size();i++)
    {
        if(map[sx][sy]==0)
        {
            map[sx][sy]=1;
            printf("1 ");
            r--;
        }
        else
        {
            printf("0 ");
        }
        if(s[i]=='U')sx=max(0,sx-1);
        if(s[i]=='D')sx=min(mx-1,sx+1);
        if(s[i]=='L')sy=max(0,sy-1);
        if(s[i]=='R')sy=min(my-1,sy+1);
    }
    printf("%d\n",r);
}