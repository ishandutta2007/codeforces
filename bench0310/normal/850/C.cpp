#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<int,int> grundy;
vector<bool> vis(30,0);

int g(int a)
{
    if(grundy.find(a)!=grundy.end()) return grundy[a];
    vector<int> v;
    int b=-1;
    for(int i=0;i<29;i++) if(a&(1<<i)) b=i;
    for(int i=0;i<=b;i++) v.push_back(g((a>>(i+1))|(a&((1<<i)-1))));
    for(int x:v) vis[x]=1;
    for(int i=0;i<=29;i++)
    {
        if(vis[i]==0)
        {
            grundy[a]=i;
            break;
        }
    }
    for(int x:v) vis[x]=0;
    return grundy[a];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int,int> m;
    while(n--)
    {
        int a;
        cin >> a;
        for(int i=2;i*i<=a;i++)
        {
            if(a%i) continue;
            int c=0;
            while((a%i)==0)
            {
                a/=i;
                c++;
            }
            m[i]|=(1<<(c-1));
        }
        if(a>1) m[a]|=1;
    }
    int x=0;
    for(auto [p,a]:m) x^=g(a);
    if(x>0) cout << "Mojtaba\n";
    else cout << "Arpa\n";
    return 0;
}