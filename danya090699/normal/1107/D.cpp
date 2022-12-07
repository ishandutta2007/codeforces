#include <bits/stdc++.h>
using namespace std;
const int sz=5300;
char ma[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, d=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        char s[sz];
        scanf("%s", s);
        for(int b=0; b<n/4; b++)
        {
            int x;
            if(s[b]>='0' and s[b]<='9') x=s[b]-'0';
            else x=s[b]-'A'+10;
            for(int i=3; i>=0; i--) ma[a][b*4+3-i]='0'+((x&(1<<i))>0);
        }
    }
    for(int a=0; a<n; a++)
    {
        int yk=0;
        while(yk<n)
        {
            char sy=ma[a][yk];
            int q=0;
            while(yk<n)
            {
                if(ma[a][yk]==sy) yk++, q++;
                else break;
            }
            d=__gcd(d, q);
        }
    }
    for(int a=0; a<n; a++)
    {
        int yk=0;
        while(yk<n)
        {
            char sy=ma[yk][a];
            int q=0;
            while(yk<n)
            {
                if(ma[yk][a]==sy) yk++, q++;
                else break;
            }
            d=__gcd(d, q);
        }
    }
    cout<<d;
}