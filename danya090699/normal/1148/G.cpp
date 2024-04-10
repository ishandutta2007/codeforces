#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, sz2=1e7+10;
int masks[sz][1<<8], dq[sz], q[sz2];
void add(int i)
{
    for(int mask=1; mask<(1<<dq[i]); mask++) q[masks[i][mask]]++;
}
int get(int i)
{
    int re=0;
    for(int mask=1; mask<(1<<dq[i]); mask++)
    {
        if(__builtin_popcount(mask)&1) re+=q[masks[i][mask]];
        else re-=q[masks[i][mask]];
    }
    return re;
}
void clean()
{
    for(int a=0; a<sz2; a++) q[a]=0;
}
int i1=-1, i2=-1, i3=-1;
bool norm(int i)
{
    return (i!=i1 and i!=i2 and i!=i3);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        ar[a]=x;
        vector <int> sp;
        for(int b=2; b*b<=x; b++)
        {
            if(x%b==0)
            {
                sp.push_back(b);
                while(x%b==0) x/=b;
            }
        }
        if(x>1) sp.push_back(x);

        dq[a]=sp.size();
        for(int mask=1; mask<(1<<dq[a]); mask++)
        {
            int va=1;
            for(int i=0; i<dq[a]; i++) if(mask&(1<<i)) va*=sp[i];
            masks[a][mask]=va;
        }
    }
    for(int a=0; a<n; a++) add(a);
    for(int a=0; a<n; a++)
    {
        if(get(a)<=n-2)
        {
            i1=a;
            for(int b=0; b<n; b++)
            {
                if(__gcd(ar[a], ar[b])==1)
                {
                    if(i2==-1) i2=b;
                    else if(i3==-1) i3=b;
                }
            }
            break;
        }
    }
    vector <int> an;
    if(i1==-1)
    {
        clean();
        for(int a=0; a<n; a++)
        {
            if(get(a)==an.size() and an.size()<k)
            {
                an.push_back(a), add(a);
            }
        }
    }
    else
    {
        vector <int> good;
        clean();
        for(int a=0; a<n; a++) add(a);
        for(int a=0; a<n; a++) if(get(a)==n) good.push_back(a);

        if(good.size()>=k)
        {
            for(int a=0; a<k; a++) an.push_back(good[a]);
        }
        else
        {
            int l=0, r=n;
            while(r-l>1)
            {
                int mid=(l+r)>>1, q=0, su=0;
                clean();
                for(int a=0; a<mid; a++)
                {
                    if(norm(a)) add(a), q++;
                }
                for(int a=0; a<mid; a++)
                {
                    if(norm(a))
                    {
                        if(get(a)!=q) su++;
                    }
                }
                if(su+3>k) r=mid;
                else l=mid;
            }
            int bad[n];
            for(int a=0; a<n; a++) bad[a]=0;
            for(int i=0; i<2; i++)
            {
                clean();
                int q=0;
                for(int a=0; a<l+i; a++)
                {
                    if(norm(a)) add(a), q++;
                }
                for(int a=0; a<l+i; a++)
                {
                    if(norm(a))
                    {
                        if(get(a)!=q)
                        {
                            bad[a]++;
                        }
                    }
                }
            }
            vector <int> add;
            for(int a=0; a<n; a++)
            {
                if(bad[a]==1) add.push_back(a);
                if(bad[a]==2) an.push_back(a);
            }
            add.push_back(i1), add.push_back(i2);
            if(an.size()+4!=k) add.push_back(i3);

            while(an.size()<k) an.push_back(add.back()), add.pop_back();
        }
    }
    for(int a=0; a<k; a++) printf("%d ", an[a]+1);
}