#include <bits/stdc++.h>
using namespace std;
int n;
char s[100];
struct fint
{
    int r,c;
};
fint v[100];
int dr[100];
int dc[100];
int r,c;
void codif(int val)
{
    if(val==0)
    {
        r=4;
        c=2;
        return;
    }
    if(val%3==0)
    {
        r=val/3;
        c=3;
        return;
    }
    r=val/3+1;
    c=val%3;
}
bool valid(int r,int c)
{
    if(r==4 and c==2)
        return 1;
    if(1<=r and 1<=c and r<=3 and c<=3)
        return 1;
    return 0;
}
bool simulate(int R,int C)
{
    for(int i=1;i<n;i++)
    {
        R+=dr[i];
        C+=dc[i];
        if(valid(R,C)==0)
            return 0;
    }
    return 1;
}
int main()
{
    int ss=0;
    cin>>n;
    cin.get();
    cin.getline(s,100);
    for(int i=0;i<n;i++)
    {
        codif(s[i]-'0');
        v[i+1].r=r;
        v[i+1].c=c;
    }
    for(int i=2;i<=n;i++)
    {
        dr[i-1]=v[i].r-v[i-1].r;
        dc[i-1]=v[i].c-v[i-1].c;
    }
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        {
            ss+=simulate(i,j);
        }
    ss+=simulate(4,2);
    if(ss==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
/**
**/