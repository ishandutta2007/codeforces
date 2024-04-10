#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
char a[65][65];
int n,m;
int check0()
{
    int f=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='P')
            {
                f=0;
                break;
            }
    return f;
}
int checkm()
{
    int f=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='A')
            {
                f=0;
                break;
            }
    return f;
}
int check1()
{
    int f=1;
    for(int i=0;i<n;i++)
        if(a[i][0]!='A')
        {
            f=0;
            break;
        }
    if(f) return f;
    f=1;
    for(int i=0;i<n;i++)
        if(a[i][m-1]!='A')
        {
            f=0;
            break;
        }
    if(f) return f;
    f=1;
    for(int i=0;i<m;i++)
        if(a[0][i]!='A')
        {
            f=0;
            break;
        }
    if(f) return f;
    f=1;
    for(int i=0;i<m;i++)
        if(a[n-1][i]!='A')
        {
            f=0;
            break;
        }
    return f;
}
int check2()
{
    int f=0;
    if(a[0][0]=='A'||a[0][m-1]=='A'||a[n-1][0]=='A'||a[n-1][m-1]=='A') f=1;
    for(int i=0;i<n;i++)
    {
        int t=1;
        for(int j=0;j<m;j++)
            if(a[i][j]!='A')
            {
                t=0;
                break;
            }
        if(t)
        {
            f=1;
            break;
        }
    }
    for(int i=0;i<m;i++)
    {
        int t=1;
        for(int j=0;j<n;j++)
            if(a[j][i]!='A')
            {
                t=0;
                break;
            }
        if(t)
        {
            f=1;
            break;
        }
    }
    return f;
}
int check4()
{
    int f=1;
    for(int i=0;i<n;i++)
        if(a[i][0]=='A'||a[i][m-1]=='A')
        {
            f=0;
            break;
        }
    for(int i=0;i<m;i++)
        if(a[0][i]=='A'||a[n-1][i]=='A')
        {
            f=0;
            break;
        }
    return f;
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++) scanf("%s",a[i]);
        if(check0()) printf("0\n");
        else if(checkm()) printf("MORTAL\n");
        else if(check1()) printf("1\n");
        else if(check2()) printf("2\n");
        else if(check4()) printf("4\n");
        else printf("3\n");
    }
}