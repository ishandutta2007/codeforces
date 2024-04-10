#include <bits/stdc++.h>

using namespace std;

const int N=1000+5;

int n;
vector<int>g[N];
int best[N];
bool is[N];
bool isy[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            isy[i]=0;
            is[i]=0;
            best[i]=-1;
            g[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int my;
        cin>>my;
        for(int i=1;i<=my;i++)
        {
            int nod;
            cin>>nod;
            is[nod]=1;
        }
        int chen,go;
        cin>>chen;
        for(int i=1;i<=chen;i++)
        {
            cin>>go;
            isy[go]=1;
        }
        queue<int>q;
        cout<<"B "<<go<<endl;
        cin>>go;
        q.push(go);
        best[go]=0;
        while(!q.empty())
        {
            int nod=q.front();
            q.pop();
            for(auto &nou:g[nod])
            {
                if(best[nou]==-1)
                {
                    best[nou]=best[nod]+1;
                    q.push(nou);
                }
            }
        }
        int midist=(1<<30),who;
        for(int i=1;i<=n;i++)
        {
            if(is[i])
            {
                midist=min(midist,best[i]);
                if(best[i]==midist)
                {
                    who=i;
                }
            }
        }
        int qq;
        cout<<"A "<<who<<endl;
        cin>>qq;
        cout<<"C ";
        if(isy[qq])
        {
            cout<<who<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    return 0;
}