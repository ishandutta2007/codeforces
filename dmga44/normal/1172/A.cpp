#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

int n,a[MAXN],b[MAXN],fs[MAXN];

bool check(int x)
{
    set<int> s;
    queue<int> q;
    for(int i=0;i<n;i++)
        q.push(b[i]),fs[i]=0;
    for(int i=0;i<n;i++)
    {
        fs[a[i]]++;
        if(a[i])
            s.insert(a[i]);
    }
    if(x>n)
    {
        int pos=0;
        while(x>n)
        {
            if(!fs[0])
                return 1;
            if(q.front())
                s.insert(q.front());
            fs[q.front()]++;
            q.pop();
            q.push(0);
            fs[0]--;
            x--;
        }
    }

    while(x--)
    {
        if(!s.size())
            return 0;
        int v=*(s.begin());
        if(v!=q.back()+1)
            return 0;
        q.push(v);
        s.erase(v);
        if(q.front())
            s.insert(q.front());
        q.pop();
    }

    bool res=1;
    for(int i=1;i<=n;i++)
    {
        res&=(i==q.front());
        q.pop();
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    int p1=0;
    for(int i=0;i<n;i++)
        if(b[i]==1)
            p1=i+1;

    bool ok=(p1!=0);
    for(int i=p1;i<n;i++)
        if(b[i]!=b[i-1]+1)
            ok=0;

    if(ok)
    {
        int x=p1-1;
        if(check(x))
        {
            db(x)
            return 0;
        }
    }

    int res=n-1;
    for(int i=(1<<17);i;i>>=1)
        if(!check(res+i))
            res+=i;
    res++;
    db(res)

    return 0;
}