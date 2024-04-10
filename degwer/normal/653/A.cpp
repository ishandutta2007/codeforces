#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    scanf("%d",&num);
    vector<int>v;
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        v.push_back(z);
    }
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            for(int k=0;k<num;k++)
            {
                if(v[i]+1==v[j]&&v[j]+1==v[k])
                {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
}