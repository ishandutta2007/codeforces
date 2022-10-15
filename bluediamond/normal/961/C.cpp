#include <bits/stdc++.h>
using namespace std;
int n,v[10][105][105];
char s[105];
int c1[10];
int c2[10];
int main()
{
    cin>>n;
    for(int i=1;i<=4;i++)
    {
        cin.get();
        for(int r=1;r<=n;r++)
        {
            cin.getline(s,105);
            for(int c=0;c<n;c++)
                v[i][r][c+1]=s[c]-'0';
        }
    }
    for(int i=1;i<=4;i++)
        for(int r=1;r<=n;r++)
            for(int c=1;c<=n;c++)
                if(v[i][r][c]!=(r+c)%2)
                    c1[i]++;
                else
                    c2[i]++;
    int best=(1<<30);

    best=min(best,c1[1]+c1[2] + c2[3]+c2[4]);
    best=min(best,c1[1]+c1[3] + c2[4]+c2[2]);
    best=min(best,c1[1]+c1[4] + c2[2]+c2[3]);
    best=min(best,c1[2]+c1[3] + c2[1]+c2[4]);
    best=min(best,c1[2]+c1[4] + c2[1]+c2[3]);
    best=min(best,c1[3]+c1[4] + c2[1]+c2[2]);
    cout<<best;
    return 0;
}
/**
1   0
0   0
**/