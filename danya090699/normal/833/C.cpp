//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int short int
using namespace std;
const int sz=18;
int lch[sz+1], rch[sz+1], q[10];
long long ans=0;
void check()
{
    bool re=1;
    int q2[10];
    for(int a=0; a<10; a++) q2[a]=q[a];
    for(int a=sz; a>=0; a--)
    {
        int le=lch[a], ri=rch[a];
        if(le==ri)
        {
            if(q2[le]>0) q2[le]--;
            else
            {
                re=0;
                break;
            }
        }
        else
        {
            bool ok=0;
            for(int b=le+1; b<ri; b++) if(q2[b]>0) ok=1;
            if(ok) break;
            if(q2[le]>0)
            {
                int q3[10], yk=9, ok=1;
                for(int a=0; a<10; a++) q3[a]=q2[a];
                q3[le]--;
                for(int b=a-1; b>=0; b--)
                {
                    while(q3[yk]==0) yk--;
                    if(yk!=lch[b])
                    {
                        if(yk<lch[b]) ok=0;
                        break;
                    }
                    q3[yk]--;
                }
                if(ok) break;
            }
            if(q2[ri]>0)
            {
                q2[ri]--;
                int yk=0, ok=1;
                for(int b=a-1; b>=0; b--)
                {
                    while(q2[yk]==0) yk++;
                    if(yk!=rch[b])
                    {
                        if(yk>rch[b]) ok=0;
                        break;
                    }
                    q2[yk]--;
                }
                if(ok) break;
            }
            re=0;
            break;
        }
    }
    ans+=re;
}
int dfs(int le, int pr)
{
    if(le==sz) check();
    else
    {
        for(int a=pr; a>=0; a--)
        {
            q[a]++;
            dfs(le+1, a);
            q[a]--;
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    long long l, r;
    cin>>l>>r;
    for(int a=0; a<=sz; a++)
    {
        lch[a]=l%10, l/=10;
        rch[a]=r%10, r/=10;
    }
    for(int a=0; a<10; a++) q[a]=0;
    q[0]++;
    dfs(0, 9);
    cout<<ans;
}