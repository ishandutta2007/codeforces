#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
int n;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    for(int i=0;i<=10;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=10;k++)
            {
                int flag=1;
                for(int p=0;p<=2000;p++)
                {
                    if (p%a==i)continue;
                    if (p%b==j)continue;
                    if (p%c==k)continue;
                    flag=0;
                    break;
                }
                if (flag){ puts("YES"); return 0; }
            }  
    puts("NO");
}