#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> pii;
#define MAXN 1000005

ll ac[MAXN],c[MAXN];
bool mk[MAXN];

int cpos(int pos,int i)
{
    if(!mk[min(MAXN-1,pos+i+1)])
        return min(MAXN-1,pos+i+1);

    int p=pos;
    for(int j=(1<<19);j;j>>=1)
        if(p+j<pos+i+1 && ac[pos+i+1]-ac[p+j-1]<(pos+i+1-p-j+1))
            p+=j;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    int n,m,k,x;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        cin >> x;
        mk[x]=1;
    }

    if(mk[0])
    {
        db(-1)
        return 0;
    }
    for(int i=0;i<k;i++)
        cin >> c[i];

    ac[0]=mk[0];
    for(int i=1;i<n;i++)
        ac[i]=ac[i-1]+mk[i];

    ll res=1e18;
    for(int i=0;i<k;i++)
    {
        ll cant=0,pos=0;
        while(pos<n)
        {
            int xxx=cpos(pos,i)-pos;
            if(xxx==0)
            {
                cant=-1;
                break;
            }
            pos+=xxx;
            cant++;
        }
        if(cant!=-1)
            res=min(res,cant*c[i]);
    }
    if(res==1e18)
        res=-1;
    db(res)
    return 0;
}