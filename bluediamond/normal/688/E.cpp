#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500+5;

int n,k;
int v[N];
bool ok[N][N][N]; /// ok [p][s1][s2]

void send(int p,int s1,int s2)
{
    if(s1>k) return;
    if(ok[p][s1][s2]) return;
    ok[p][s1][s2]=1;
    if(p==n)
    {
        return;
    }
    send(p+1,s1,s2);
    send(p+1,s1+v[p+1],s2);
    send(p+1,s1+v[p+1],s2+v[p+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    send(0,0,0);
    vector<int>ans;
    for(int i=0;i<=k;i++)
    {
        if(ok[n][k][i])
        {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto &it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

2 9
3 3

**/