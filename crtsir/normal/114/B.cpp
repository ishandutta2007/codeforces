#include<bits/stdc++.h>
using namespace std;
map<string,int>p;
int g[17][17];
string str[17];
int countbit(int n)
{
    int ret=0;
    while(n)
    {
        ret+=n%2;
        n/=2;
    }
    return ret;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        p[str[i]]=i;
    }
    for(int i=0;i<m;i++)
    {
        string x,y;
        cin>>x>>y;
        g[p[x]][p[y]]=1;
        g[p[y]][p[x]]=1;
    }
    int ans=0;
    for(int state=0;state<=(1<<n);state++)
    {
        if(countbit(ans)>=countbit(state))continue;
        bool fl=false;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((state&(1<<i))&&(state&(1<<j))&&g[i][j])
                    fl=true;
        if(!fl)
            ans=state;
    }
    vector<string>w;
    for(int i=0;i<n;i++)
        if((ans&(1<<i)))
            w.push_back(str[i]);
    cout<<w.size();
    sort(w.begin(),w.end());
    for(int i=0;i<w.size();i++)
        cout<<endl<<w[i];
}