#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int num,gen;
    scanf("%d%d",&num,&gen);
    int t=num-gen;
    if(t<0)t=0;
    vector<int>v;
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        v.push_back(z);
    }
    int maxi=0;
    for(int i=0;i<t;i++)
    {
        maxi=max(maxi,v[i]+v[t*2-1-i]);
    }
    for(int i=t*2;i<num;i++)maxi=max(maxi,v[i]);
    printf("%d\n",maxi);
}