#include<bits/stdc++.h>
using namespace std;
vector<int> fac;
void Find_factor(int n)
{
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0){
            fac.push_back(i);
            if(i!=sqrt(n)) fac.push_back(n/i);
        }
    }
    sort(fac.begin(),fac.end());
}
int main()
{
    int n;
    scanf("%d",&n);
    Find_factor(n);
    for(int i=fac.size()-1;i>=0;i--)
    {
        long long ans=1LL*(1+n-fac[i]+1)*(n/fac[i])/2;
        printf("%lld ",ans);
    }
}