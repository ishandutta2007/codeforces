#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 10005

short abi[MAXN][MAXN];
int ab[MAXN];

void upd(int p)
{
    while(p<MAXN)
    {
        ab[p]++;
        p+=(p&-p);
    }
}

int qry(int p)
{
    int res=0;
    while(p)
    {
        res+=ab[p];
        p-=(p&-p);
    }
    return res;
}

void update(int p,int r)
{
    while(r<MAXN)
    {
        int pp=p;
        while(pp<MAXN)
        {
            abi[r][pp]++;
            pp+=(pp&-pp);
        }
        r+=(r&-r);
    }
}

int query(int p,int r)
{
    int res=0;
    while(r)
    {
        int pp=p;
        while(pp)
        {
            res+=abi[r][pp];
            pp-=(pp&-pp);
        }
        r-=(r&-r);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x1,y1,x2,y2;
    cin >> n;
    vector<ppp> ver,hor;
    int t=0;
    for(int i=0;i<n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=5001;
        y1+=5001;
        x2+=5001;
        y2+=5001;
        if(x1>x2)
            swap(x1,x2);
        if(y1>y2)
            swap(y1,y2);
        if(x1==x2)
        {
            ver.push_back(ppp(pii(x1,y1),pii(x2,y2)));
            t++;
        }
        else
            hor.push_back(ppp(pii(y1,x1),pii(y2,x2)));
    }

    int p=0;
    ll res=0,cant;
    if(t>(n/2))
    {
        for(int i=0;i<ver.size();i++)
        {
            swap(ver[i].first.first,ver[i].first.second);
            swap(ver[i].second.first,ver[i].second.second);
        }

        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());

        for(int i=0;i<hor.size();i++)
        {
//            cout << hor[i].first.first << ' ' << hor[i].second.first << ' ' << hor[i].first.second << '\n';
//            db("xx")
            while(p<ver.size() && ver[p].first.first<=hor[i].first.first)
            {
                upd(ver[p].first.second);
                update(ver[p].second.first,ver[p].first.second);
//                cout << ver[p].first.first << ' ' << ver[p].second.first << ' ' << ver[p].first.second << '\n';
                p++;
            }
//            db("")

            for(int j=i+1;j<hor.size();j++)
            {
                int l2=hor[j].first.first;
                x1=max(hor[i].first.second,hor[j].first.second);
                x2=min(hor[i].second.second,hor[j].second.second);
                if(x1>x2)
                    continue;
                cant=query(l2-1,x2)-query(l2-1,x1-1);
//                db(cant)
                cant=qry(x2)-qry(x1-1)-cant;
                res+=((cant*(cant-1ll))/2ll);
            }
//            db(i)
//            db("")
//            db("")
        }
    }
    else
    {
        for(int i=0;i<hor.size();i++)
        {
            swap(hor[i].first.first,hor[i].first.second);
            swap(hor[i].second.first,hor[i].second.second);
        }

        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());

        for(int i=0;i<ver.size();i++)
        {
            while(p<hor.size() && hor[p].first.first<=ver[i].first.first)
            {
                upd(hor[p].first.second);
                update(hor[p].second.first,hor[p].first.second);
                p++;
            }

            for(int j=i+1;j<ver.size();j++)
            {
                int l2=ver[j].first.first;
                x1=max(ver[i].first.second,ver[j].first.second);
                x2=min(ver[i].second.second,ver[j].second.second);
                if(x1>x2)
                    continue;
                cant=query(l2-1,x2)-query(l2-1,x1-1);
                cant=qry(x2)-qry(x1-1)-cant;
                res+=((cant*(cant-1ll))/2ll);
            }
        }
    }
    db(res)

    return 0;
}
/**
7
-1 4 -1 -2
6 -1 -2 -1
-2 3 6 3
2 -2 2 4
4 -1 4 3
5 3 5 1
5 2 1 2
**/