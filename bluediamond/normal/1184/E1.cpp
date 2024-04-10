#include <bits/stdc++.h>

using namespace std;

int n,m;
vector <int> t;

int get(int a)
{
        if(t[a]==a)
        {
                return a;
        }
        else
        {
                return t[a]=get(t[a]);
        }
}

struct kek
{
        int a;
        int b;
        int c;
};

bool operator < (kek a,kek b)
{
        return a.c<b.c;
}

void uni(int a,int b)
{
        a=get(a);
        b=get(b);
        if(a!=b)
                t[a]=b;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n+1;i++)
                t.push_back(i-1);
        m--;
        vector <kek> e(m);
        int a,b,c;
        cin>>a>>b>>c;
        for(int i=0;i<m;i++)
                cin>>e[i].a>>e[i].b>>e[i].c;
        sort(e.begin(),e.end());
        int sol=0;
        if(m==0)
        {
                sol=(int)1e9;
        }
        for(int i=0;i<m;i++)
        {
                auto it=e[i];
                int x=it.a;
                int y=it.b;
                int z=it.c;
                if(get(a)!=get(b))
                        sol=max(sol,e[i].c);
                uni(x,y);
                int urm;
                if(i+1==m)
                        urm=(int)1e9;
                else
                        urm=max(e[i].c,e[i+1].c-1);
                if(get(a)!=get(b))
                        sol=max(sol,urm);

        }
        cout<<sol<<"\n";
        return 0;
}