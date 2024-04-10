#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> depth(N,0);
int k;
ll res=0;

int f(int a)
{
    if(a>=0) return (a+k-1)/k;
    else return (a/k);
}

vector<array<ll,2>> dfs(int a,int p=0)
{
    depth[a]=depth[p]+1;
    vector<array<ll,2>> x(k,{0,0});
    x[depth[a]%k]={depth[a]/k,1};
    for(int to:v[a])
    {
        if(to==p) continue;
        vector<array<ll,2>> y=dfs(to,a);
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                ll now=(x[i][0]*y[j][1]+y[j][0]*x[i][1]-2*(depth[a]/k)*x[i][1]*y[j][1]);
                int d=i+j-2*(depth[a]%k);
                now+=(f(d)*x[i][1]*y[j][1]);
                res+=now;
                //cout << "adding " << now << "(" << a << ")" << endl;
            }
        }
        for(int j=0;j<k;j++)
        {
            x[j][0]+=y[j][0];
            x[j][1]+=y[j][1];
        }
    }
    //cout << "out " << a << endl;
    //for(int i=0;i<k;i++) cout << i << ": sum=" << x[i][0] << " cnt=" << x[i][1] << endl;
    //cout << endl;
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> k;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout << res << "\n";
    return 0;
}