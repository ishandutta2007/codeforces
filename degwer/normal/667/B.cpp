#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int num;
    scanf("%d",&num);
    ll sum=0,maxi=0;
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        sum+=z;
        maxi=max(maxi,(ll)z);
    }
    printf("%I64d\n",maxi-(sum-maxi)+1);
}