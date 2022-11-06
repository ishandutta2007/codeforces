#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b)
    {
        cout<<-1;
        return 0;
    }
    int x=a+b,y=a-b;
    long long z=1,w=inf*2;
    double ans=1e10;
    if(y/2>=b)
    {
        while(w!=z)
        {
            long long mid=(z+w+1)/2;
            if(y/(2*mid)>=b)
            z=mid;
        else
            w=mid-1;
        }
        ans=min(ans,y/(double)(2*w));
    }
    z=1,w=inf*2;    
    while(w!=z)
    {
        long long mid=(z+w+1)/2;
        if(x/(2*mid)>=b)
            z=mid;
        else
            w=mid-1;
    }
    ans=min(ans,x/(double)(2*w));
    printf("%.11f",ans);        
}