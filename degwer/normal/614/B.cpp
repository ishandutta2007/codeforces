#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int num;
    scanf("%d",&num);
    int r=0;
    string s="1";
    bool t=false;
    for(int i=0;i<num;i++)
    {
        string z;
        cin>>z;
        if(z=="0")t=true;
        bool f=true;
        for(int j=0;j<z.size();j++)
        {
            if((j==0&&z[j]!='1')||(j!=0&&z[j]!='0'))
            {
                s=z;
                f=false;
                break;
            }
        }
        if(f)
        {
            r+=z.size()-1;
        }
    }
    if(t)
    {
        printf("0\n");
        return 0;
    }
    cout<<s;
    for(int i=0;i<r;i++)printf("0");
    printf("\n");
}