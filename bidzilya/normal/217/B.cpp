#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
const double eps = 1e-8;

int n,r;
char c[1000001],a[1000001];
int an = MAX_INT;

void check(int x, int y)
{
     int len = 0;
     while (x!=y && len<n-1)
     {
           len++;
           if (x>=y)
           {
                   x -= y;
                   c[len-1]='T';
           }else
           {
                y -= x;
                c[len-1] = 'B';
           }
     }
     if (len!=(n-1) || x!=y || x!=1)return;
     c[len]='T';
     len++;
     int ta = 0;
     for (int i=n-2;i>=0;i--)
         if (c[i]==c[i+1])
            ta++;
     if (ta<an)
     {
               an = ta;
               for (int i=0;i<n;i++)a[i]=c[i];
     }
}

int main()
{
    scanf("%d%d",&n,&r);
    for (int i=1;i<=r;i++){check(i,r);check(r,i);}
    
    if (an==MAX_INT)
       printf("IMPOSSIBLE\n");
    else
    {
        printf("%d\n",an);
        for (int i=n-1;i>=0;i--)printf("%c",a[i]);
        printf("\n");
    }
 //   system("pause");
    return 0;
}