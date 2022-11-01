#include <bits/stdc++.h>

using namespace std;

const int N=1179858;
vector<bool> prime(N+1,1);

void ini()
{
    prime[0]=prime[1]=0;
    for(int o=2;o*o<=N;o++)
    {
        if(prime[o]==0) continue;
        for(int i=o*o;i<=N;i+=o) prime[i]=0;
    }
}

bool pal(int a)
{
    vector<int> v;
    while(a)
    {
        v.push_back(a%10);
        a/=10;
    }
    for(int i=0;i<(int)v.size();i++) if(v[i]!=v[v.size()-1-i]) return 0;
    return 1;
}

int main()
{
    ini();
    long long p,q;
    scanf("%I64d%I64d",&p,&q);
    long long a=0,b=0;
    int res=0;
    for(int i=1;i<=N;i++)
    {
        a+=prime[i];
        b+=pal(i);
        if(a*q<=b*p) res=i;
    }
    if(res) printf("%d\n",res);
    else printf("Palindromic tree is better than splay tree\n");
    return 0;
}