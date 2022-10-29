#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    scanf("%d",&num);
    vector<int>va,vb;
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        if(z!=0)va.push_back(z);
    }
    for(int i=0;i<num;i++)
    {
        int z;
        scanf("%d",&z);
        if(z!=0)vb.push_back(z);
    }
    int st;
    for(int i=0;i<vb.size();i++)if(vb[i]==va[0])st=i;
    vector<int>ans;
    for(int i=st;i<vb.size();i++)ans.push_back(vb[i]);
    for(int i=0;i<st;i++)ans.push_back(vb[i]);
    if(va==ans)printf("YES\n");
    else printf("NO\n");
}