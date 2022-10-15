#include<bits/stdc++.h>
using namespace std;
const int nmax=100000;
struct data
{
    long long nr_s=0,nr_h=0,value=0;
};
int n;
data v[nmax+5];
char s[nmax+5];
bool cmp(data a,data b)
{
    long long X,Y;
    X=1ll*a.nr_s*b.nr_h;
    Y=1ll*b.nr_s*a.nr_h;
    return X>Y;
}
int main()
{
    cin>>n;
    cin.get();
    for(int k=1;k<=n;k++)
    {
        cin.getline(s,nmax+5);
        int m=strlen(s);
        for(int i=0;i<m;i++)
        {
            if(s[i]=='s')
                v[k].nr_s++;
            if(s[i]=='h')
            {
                v[k].nr_h++;
                v[k].value+=v[k].nr_s;
            }
        }
    }
    sort(v+1,v+n+1,cmp);
    long long ans=0,cate_s=0;
    for(int i=1;i<=n;i++)
    {
        ans+=v[i].value;
        ans+=1ll*cate_s*v[i].nr_h;
        cate_s+=v[i].nr_s;
    }
    cout<<ans;
    return 0;
}
/**
6
h
s
hhh
h
ssssss
s
**/