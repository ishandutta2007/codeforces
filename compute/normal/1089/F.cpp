#include<bits/stdc++.h>
using namespace std;
vector<int> factor;
void found(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            factor.push_back(i);
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n>1) factor.push_back(n);
}
int main()
{
    int n;
    scanf("%d",&n);
    found(n);
    if(factor.size()<=1)
        puts("NO");
    else{
        puts("YES");
        printf("2\n");
        sort(factor.begin(),factor.end());
        int one=factor[0],two=factor[1];
        int facone=0,factwo=0;
        for(int i=0;i*two<=n-1;i++)
        {
            if((n-1-i*two)%factor[0]==0)
            {
                factwo=i;
                facone=(n-1-i*two)/one;
            }
        }
        printf("%d %d\n%d %d\n",factwo,n/two,facone,n/one);
    }
}