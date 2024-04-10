#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
typedef long long LL;
char s[105];
int main()
{
    int i,n;
    bool f1=0,f2=0,f3=0;
    cin>>s;
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        if(s[i]>=65&&s[i]<65+26)
            f1=1;
        else if(s[i]>=48&&s[i]<=48+9)
            f2=1;
        else if(s[i]>=97&&s[i]<=97+25)
            f3=1;
    }
    if(n>=5&&f1&&f2&&f3)
        printf("Correct\n");
    else
        printf("Too weak\n");
    return 0;
}
// davidlee1999WTK 2014/
//ios::sync_with_stdio(false);