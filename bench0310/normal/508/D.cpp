#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=3844;
vector<int> v[N];
vector<int> euler;

void solve(int a)
{
    while(!v[a].empty())
    {
        int to=v[a].back();
        v[a].pop_back();
        solve(to);
    }
    euler.push_back(a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string alpha;
    for(char c='a';c<='z';c++) alpha+=c;
    for(char c='A';c<='Z';c++) alpha+=c;
    for(char c='0';c<='9';c++) alpha+=c;
    vector<string> f(N);
    map<string,int> h;
    int idx=0;
    for(char a:alpha)
    {
        for(char b:alpha)
        {
            string s=string(1,a)+b;
            f[idx]=s;
            h[s]=idx++;
        }
    }
    int n;
    cin >> n;
    vector<int> in(N,0);
    vector<int> out(N,0);
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int a=h[s.substr(0,2)];
        int b=h[s.substr(1,2)];
        v[a].push_back(b);
        out[a]++;
        in[b]++;
    }
    int s=-1;
    int t=-1;
    bool ok=1;
    for(int i=0;i<N;i++)
    {
        ok&=(abs(in[i]-out[i])<=1);
        if(in[i]-out[i]==-1)
        {
            if(s==-1) s=i;
            else ok=0;
        }
        if(in[i]-out[i]==1)
        {
            if(t==-1) t=i;
            else ok=0;
        }
    }
    if(s!=-1||t!=-1) ok&=(s!=-1&&t!=-1);
    if(ok==1)
    {
        if(s==-1)
        {
            for(int i=0;i<N;i++) if(in[i]!=0) s=i;
        }
        solve(s);
        if((int)euler.size()!=n+1)
        {
            cout << "NO\n";
            return 0;
        }
        reverse(euler.begin(),euler.end());
        string res=f[euler[0]];
        for(int i=1;i<(int)euler.size();i++) res+=f[euler[i]][1];
        cout << "YES\n";
        cout << res << "\n";
    }
    else cout << "NO\n";
    return 0;
}