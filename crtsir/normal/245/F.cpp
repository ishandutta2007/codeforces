#include<bits/stdc++.h>
using namespace std;
char ss[5000002];
string ans[5000002];
int w[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int a[1000020],c,n,m;
int main()
{
    for(int i=1;i<=12;i++)
        w[i]+=w[i-1];
    cin>>n>>m;
    gets(ss);
    while(gets(ss)){
        int y,mm,d,h,mmm,s;
        sscanf(ss,"%d-%d-%d %d:%d:%d:",&y,&mm,&d,&h,&mmm,&s);
        if(ss[0]!='2')continue;
        //cout<<ss<<endl;
        int sec=w[mm-1]+d-1;
        sec*=86400;
        sec+=h*3600+mmm*60+s;
        ans[c]=ss;
        a[c++]=sec;
    }
    int l=0;
    for(int i=0;i<c;i++)
    {
        while(a[i]-a[l]>=n)
            l++;
        if(i-l+1>=m)
        {
            cout<<ans[i].substr(0,19);
            return 0;
        }
    }
    cout<<-1;
}