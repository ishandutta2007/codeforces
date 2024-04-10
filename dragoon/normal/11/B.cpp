#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

//typedef __int64 LL;
//#define I64d "%I64d"
//typedef long long LL;
//#define I64d "%lld"

int main() 
{
    __int64 x,s,n;

    scanf("%I64d",&x);

    if(x<0) x=-x;

    if(x==0) { printf("0\n"); return 0;}

    s = (-1 + sqrt(1. + 8*x))/2.;

    while( (s*s+s)/2 < x ) s++;

    while(1)
    {
        n = (s*s+s)/2;

        if(n%2==1 && x%2==1) break;
        if(n%2==0 && x%2==0) break;

        s++;
    }

    printf("%I64d\n",s);


    return 0;
}