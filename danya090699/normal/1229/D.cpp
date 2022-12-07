#include <bits/stdc++.h>
using namespace std;
int fact[6]={1, 1, 2, 6, 24, 120}, n, k;
void f(int nu, int *ar)
{
    for(int a=0; a<k; a++)
    {
        int i=nu/fact[k-1-a];
        vector <int> pos;
        for(int b=0; b<k; b++)
        {
            bool ok=1;
            for(int c=0; c<a; c++) if(ar[c]==b) ok=0;
            if(ok) pos.push_back(b);
        }
        ar[a]=pos[i], nu%=fact[k-1-a];
    }
}
int f2(int *ar)
{
    int re=0;
    vector <int> us;
    for(int a=0; a<k; a++)
    {
        int i=ar[a];
        for(int b=0; b<us.size(); b++) if(us[b]<ar[a]) i--;
        re+=fact[k-1-a]*i;
        us.push_back(ar[a]);
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    int sm[fact[k]][fact[k]];
    for(int a=0; a<fact[k]; a++)
    {
        int p1[k];
        f(a, p1);
        for(int b=0; b<fact[k]; b++)
        {
            int p2[k], p3[k];
            f(b, p2);
            for(int c=0; c<k; c++) p3[c]=p1[p2[c]];

            sm[a][b]=f2(p3);
        }
    }
    vector <int> st[fact[k]];
    int ar[n];
    for(int a=0; a<n; a++)
    {
        int p[k];
        for(int b=0; b<k; b++) scanf("%d", &p[b]), p[b]--;
        ar[a]=f2(p);
        st[ar[a]].push_back(a);
    }
    long long an=0;
    for(int a=n-1; a>=0; a--)
    {
        bool us[fact[k]];
        vector <int> sp;
        for(int b=0; b<fact[k]; b++)
        {
            us[b]=0;
            if(st[b].size()) sp.push_back(st[b].back());
        }
        sort(sp.begin(), sp.end(), greater <int>());
        sp.push_back(-1);
        us[0]=1;
        int su=1;
        vector <int> re;
        for(int b=0; b+1<sp.size(); b++)
        {
            int nu=ar[sp[b]];
            if(us[nu]==0)
            {
                re.push_back(nu);
                queue <int> qu;
                for(int c=0; c<fact[k]; c++)
                {
                    if(us[c])
                    {
                        int ne=sm[c][nu];
                        if(us[ne]==0)
                        {
                            us[ne]=1, su++, qu.push(ne);
                        }
                    }
                }
                while(qu.size())
                {
                    int v=qu.front();
                    for(int c=0; c<re.size(); c++)
                    {
                        int ne=sm[v][re[c]];
                        if(us[ne]==0)
                        {
                            us[ne]=1, su++, qu.push(ne);
                        }
                    }
                    qu.pop();
                }
            }
            an+=su*(sp[b]-sp[b+1]);
        }
        st[ar[a]].pop_back();
    }
    cout<<an;
}