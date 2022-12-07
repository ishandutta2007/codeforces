#include <bits/stdc++.h>
using namespace std;
bitset <200> dp[1<<9][1<<9];
void get(int x, vector <int> &sp)
{
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            while(x%a==0) x/=a;
            sp.push_back(a);
        }
    }
    if(x>1) sp.push_back(x);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    vector <int> sp[2];
    get(ar[0], sp[0]);
    for(int a=1; a<min(n, int(sp[0].size())+2); a++)
    {
        get(ar[a], sp[1]);
        vector <int> lef[2], nu, mask[2];
        for(int i=0; i<2; i++) lef[i].resize(sp[i].size(), sp[i^1].size()+1);
        dp[(1<<sp[0].size())-1][(1<<sp[1].size())-1]=1;
        for(int b=1; b<n; b++)
        {
            if(b!=a)
            {
                int fo=0, msk[2]={0, 0};
                for(int i=0; i<2; i++)
                {
                    for(int c=0; c<sp[i].size(); c++)
                    {
                        if(ar[b]%sp[i][c])
                        {
                            if(lef[i][c]) lef[i][c]--, fo=1;
                        }
                        else msk[i]+=(1<<c);
                    }
                }
                if(fo)
                {
                    int q=nu.size();
                    for(int m1=0; m1<(1<<sp[0].size()); m1++)
                    {
                        for(int m2=0; m2<(1<<sp[1].size()); m2++)
                        {
                            if(dp[m1][m2][q])
                            {
                                dp[m1&msk[0]][m2][q+1]=1;
                                dp[m1][m2&msk[1]][q+1]=1;
                            }
                        }
                    }
                    nu.push_back(b), mask[0].push_back(msk[0]), mask[1].push_back(msk[1]);
                }
            }
        }
        if(dp[0][0][nu.size()])
        {
            int an[n], m1=0, m2=0;
            for(int b=0; b<n; b++) an[b]=2;
            an[0]=1;
            while(nu.size())
            {
                int i=nu.back(), mask1=mask[0].back(), mask2=mask[1].back();
                nu.pop_back(), mask[0].pop_back(), mask[1].pop_back();
                for(int b=0; b<(1<<sp[0].size()); b++)
                {
                    if((b&mask1)==m1 and dp[b][m2][nu.size()])
                    {
                        m1=b, an[i]=1;
                        break;
                    }
                }
                if(an[i]==2)
                {
                    for(int b=0; b<(1<<sp[1].size()); b++)
                    {
                        if((b&mask2)==m2 and dp[m1][b][nu.size()])
                        {
                            m2=b;
                            break;
                        }
                    }
                }
            }
            cout<<"YES\n";
            for(int b=0; b<n; b++) printf("%d ", an[b]);

            return 0;
        }
        for(int m1=0; m1<(1<<sp[0].size()); m1++)
        {
            for(int m2=0; m2<(1<<sp[1].size()); m2++) dp[m1][m2].reset();
        }
        sp[1].clear();
    }
    cout<<"NO";
}