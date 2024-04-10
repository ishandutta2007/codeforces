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

vector <pair <int, int>> w[(int)1e5+7];
map <pair <int,int>, int> sol;

int abi;
void uni(int a,int b)
{
        a=get(a);
        b=get(b);
        if((int)w[a].size()<(int)w[b].size())
                swap(a,b);

        /// la ala mai mare il pun pe ala mai mic
        /// la a pun pb b
        /// a > b
        t[b]=a;
        while(w[b].size())
        {
                pair <int,int> it=w[b].back();
                w[b].pop_back();
                int x=it.first,y=it.second;
                //cout<<":"<<x<<" "<<y<<"\n";
                if(get(x)==get(y))
                {
                        //cout<<"aici\n";
                        if(sol[{x,y}]==0)
                        {
                                //cout<<"* "<<x<<" "<<y<<"\n";
                                sol[{x,y}]=abi+1;
                        }
                }
                else
                {
                        w[a].push_back(it);
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n+1;i++)
                t.push_back(i-1);
        vector <kek> e(m);
        for(int i=0;i<m;i++)
                cin>>e[i].a>>e[i].b>>e[i].c;
        vector <kek> e2=e;
        sort(e.begin(),e.end());
        vector <pair <int,int>> ko;
        for(int i=0;i<m;i++)
        {
                if(get(e[i].a)==get(e[i].b))
                {
                        ko.push_back({e[i].a,e[i].b});
                }
                else
                {
                        uni(e[i].a,e[i].b);
                }
        }
        for(int i=1;i<=n;i++)
                t[i]=i;
        for(auto &it:ko)
        {
                int x=it.first,y=it.second;
                w[x].push_back(it);
                w[y].push_back(it);
        }
        for(int i=0;i<m;i++)
        {
                if(get(e[i].a)!=get(e[i].b))
                {
                        abi=e[i].c;
                        uni(e[i].a,e[i].b);
                }
        }
        for(int i=0;i<m;i++)
        {
                int x=e2[i].a,y=e2[i].b;
                int val=sol[{x,y}];
                if(val)
                {
                        cout<<val-1<<"\n";
                }
        }
        return 0;
}