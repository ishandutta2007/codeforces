#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int num;
    scanf("%d",&num);
    string s;
    cin>>s;
    vector<int>v;
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        v.push_back(z);
    }
    int now=0;
    for(int p=0;;p++)
    {
        if(now<0||now>=num)
        {
            printf("FINITE\n");
            break;
        }
        if(p>num+10000)
        {
            printf("INFINITE\n");
            break;
        }
        if(s[now]=='>')now+=v[now];
        else now-=v[now];
    }
}