#include <bits/stdc++.h>
#define int long long
using namespace std;
int tr[30][30];
int po(int x, int y)
{
    int re=1;
    for(int a=0; a<y; a++) re*=x;
    return re;
}
int f(int x)
{
    vector <int> ch;
    while(x)
    {
        ch.push_back(x%10), x/=10;
    }
    reverse(ch.begin(), ch.end());
    int q=0, re=0;
    for(int a=0; a<ch.size(); a++)
    {
        int zi=ch[a];
        for(int b=zi-1; b>=0; b--)
        {
            if(b>0) q++;
            for(int c=0; (q+c<=3 and ch.size()-a-1>=c); c++)
            {
                re+=tr[ch.size()-a-1][c]*po(9, c);
            }
            if(b>0) q--;
        }
        if(zi>0) q++;
    }
    if(q<=3) re++;
    return re;
}
main()
{
    for(int a=0; a<30; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=tr[a-1][b-1]+tr[a-1][b];
    }
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int l, r;
        cin>>l>>r;
        cout<<f(r)-f(l-1)<<"\n";
    }
}