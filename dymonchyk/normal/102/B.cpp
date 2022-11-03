#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stack>
#include <ctime>
#pragma comment(linker,"/STACK:64000000")

#define ll long long

using namespace std;

char str[100002];

int get(int a)
{
    int ret=0;
    while(a)
    {
        ret+=a%10;
        a/=10;
    }
    return ret;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int sum=0,l=strlen(str);
    for(int i=l-1;i>=0;i--)
        sum+=str[i]-'0';
    int ans=1;
    if (l==1)
    {
        cout << 0 << endl;
        return 0;
    }
    while(sum>=10)
    {
        sum=get(sum);
        ans++;
    }
    cout << ans << endl;
    return 0;
}