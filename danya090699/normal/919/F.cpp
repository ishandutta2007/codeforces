#include <bits/stdc++.h>
using namespace std;
const int sz=9*9*9*9*9;
int f(int *q)
{
    int st=1, re=0;
    for(int a=0; a<5; a++)
    {
        re+=q[a]*st, st*=9;
    }
    return re;
}
void f2(int mask, int *q)
{
    for(int a=0; a<5; a++)
    {
        q[a]=mask%9, mask/=9;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    vector <int> av;
    for(int a=0; a<sz; a++)
    {
        int q[5];
        f2(a, q);
        int su=0;
        for(int b=0; b<5; b++) su+=q[b];
        if(su==8) av.push_back(a);
    }
    queue <pair <int, int> > qu;
    map <pair <int, int>, int> dp, left;
    map <pair <int, int>, vector <pair <int, int> > > sv;
    for(int a=0; a<av.size(); a++)
    {
        for(int b=0; b<av.size(); b++)
        {
            pair <int, int> cu=make_pair(av[a], av[b]);
            int q1[5], q2[5];
            f2(av[a], q1), f2(av[b], q2);
            if(q1[0]!=8)
            {
                if(q2[0]==8)
                {
                    dp[cu]=0;
                    qu.push(cu);
                }
                else
                {
                    for(int c=1; c<5; c++)
                    {
                        for(int d=1; d<5; d++)
                        {
                            if(q1[c] and q2[d])
                            {
                                int q3[5];
                                for(int e=0; e<5; e++) q3[e]=q1[e];
                                q3[c]--, q3[(c+d)%5]++;
                                sv[make_pair(av[b], f(q3))].push_back(cu);
                                left[cu]++;
                            }
                        }
                    }
                }
            }
        }
    }
    while(qu.size())
    {
        pair <int, int> cu=qu.front();
        if(dp[cu]==0)
        {
            for(int a=0; a<sv[cu].size(); a++)
            {
                pair <int, int> pr=sv[cu][a];
                if(dp.find(pr)==dp.end())
                {
                    dp[pr]=1, qu.push(pr);
                }
            }
        }
        else
        {
            for(int a=0; a<sv[cu].size(); a++)
            {
                pair <int, int> pr=sv[cu][a];
                left[pr]--;
                if(left[pr]==0 and dp.find(pr)==dp.end())
                {
                    dp[pr]=0, qu.push(pr);
                }
            }
        }
        qu.pop();
    }
    int t;
    cin>>t;
    for(int a=0; a<t; a++)
    {
        int ff, q1[5], q2[5];
        scanf("%d", &ff);
        for(int b=0; b<5; b++)
        {
            q1[b]=0, q2[b]=0;
        }
        for(int b=0; b<8; b++)
        {
            int x;
            scanf("%d", &x);
            q1[x]++;
        }
        for(int b=0; b<8; b++)
        {
            int x;
            scanf("%d", &x);
            q2[x]++;
        }
        pair <int, int> s=make_pair(f(q1), f(q2));
        if(ff) swap(s.first, s.second);
        if(dp.find(s)==dp.end()) printf("Deal\n");
        else
        {
            if(dp[s])
            {
                if(ff==0) printf("Alice\n");
                else printf("Bob\n");
            }
            else
            {
                if(ff==0) printf("Bob\n");
                else printf("Alice\n");
            }
        }
    }
}