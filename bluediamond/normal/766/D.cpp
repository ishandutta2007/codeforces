#include <iostream>
#include <unordered_map>

using namespace std;

const int N=100000+5;
unordered_map<string,int>table;
int dad[2*N],h[2*N];

inline void init(register int n)
{
    for(register int i=1;i<=n;i++)
    {
        dad[i]=i;
        h[i]=1;
    }
}

inline int find_dad(register int a)
{
    if(dad[a]==a)
        return a;
    return dad[a]=find_dad(dad[a]);
}

inline void join(register int a,register int b)
{
    if(h[a]<h[b])
        dad[a]=b;
    else
    {
        dad[b]=a;
        if(h[a]==h[b])
            h[b]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    register int n,m,q;
    cin>>n>>m>>q;
    for(register int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        table[s]=i;
    }
    init(2*n);
    for(register int i=1;i<=m;i++)
    {
        register int tip,x,y;
        string a,b;
        cin>>tip>>a>>b;
        x=table[a];
        y=table[b];
        if(tip==1)
        {
            if(find_dad(x)==find_dad(y+n))
                cout<<"NO\n";
            else
            {
                cout<<"YES\n";
                join(find_dad(x),find_dad(y));
                join(find_dad(x+n),find_dad(y+n));
            }
        }
        else
        {
            if(find_dad(x)==find_dad(y))
                cout<<"NO\n";
            else
            {
                cout<<"YES\n";
                join(find_dad(x),find_dad(y+n));
                join(find_dad(x+n),find_dad(y));
            }
        }
    }
    for(register int i=1;i<=q;i++)
    {
        register int x,y;
        string a,b;
        cin>>a>>b;
        x=table[a];
        y=table[b];
        if(find_dad(x)==find_dad(y))
            cout<<"1\n";
        else
            if(find_dad(x)==find_dad(y+n))
                cout<<"2\n";
            else
                cout<<"3\n";
    }
    return 0;
}