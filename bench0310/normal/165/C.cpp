#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    scanf("%d",&k);
    char s[1000001];
    scanf("%s",s);
    int n=strlen(s);
    vector<long long> v;
    v.push_back(-1);
    for(int i=0;i<n;i++) if(s[i]=='1') v.push_back(i);
    v.push_back(n);
    long long res=0;
    if(k==0) for(int i=1;i<(int)v.size();i++) res+=((v[i]-v[i-1])*(v[i]-v[i-1]-1)/2);
    else for(int i=1;i+k-1<(int)v.size()-1;i++) res+=((v[i]-v[i-1])*(v[i+k]-v[i+k-1]));
    printf("%I64d\n",res);
    return 0;
}