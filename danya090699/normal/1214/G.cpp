#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10, sz2=33;
unsigned long long va[sz][sz2], bg=-1;
list <int> us;
list <int>::iterator iter[sz];

void check(int i, int j)
{
    for(int a=0; a<sz2; a++)
    {
        if((va[i][a]&va[j][a])!=va[j][a])
        {
            us.push_front(i);
            iter[i]=us.begin();
            break;
        }
    }
}
set <pair <int, int>, greater <pair <int, int> > > se;
set <pair <int, int> >::iterator pos[sz];
int fpr(auto it)
{
    if(it!=se.begin())
    {
        it--;
        return (*it).second;
    }
    else return -1;
}
int fne(auto it)
{
    it++;
    if(it!=se.end()) return (*it).second;
    else return -1;
}
main()
{
    unsigned long long mask[64], one[64];
    mask[0]=1, one[0]=1;
    for(int i=1; i<64; i++) one[i]=one[i-1]<<1, mask[i]=mask[i-1]+one[i];

    //freopen("input.txt", "r", stdin);
    int n, m, qq;
    cin>>n>>m>>qq;
    int q[n];
    for(int a=0; a<n; a++)
    {
        pos[a]=se.insert({0, a}).first;
        iter[a]=us.end(), q[a]=0;
    }
    for(int a=0; a<qq; a++)
    {
        int r, lg, rg;
        scanf("%d%d%d", &r, &lg, &rg);
        r--, lg--, rg--;

        int pr=fpr(pos[r]), ne=fne(pos[r]);

        se.erase(pos[r]);

        if(pr!=-1 and iter[pr]!=us.end()) us.erase(iter[pr]), iter[pr]=us.end();

        if(iter[r]!=us.end()) us.erase(iter[r]), iter[r]=us.end();

        if(pr!=-1 and ne!=-1) check(pr, ne);

        q[r]=0;
        for(int b=0; b<sz2; b++)
        {
            int ll=(b<<6), rr=ll+63;
            ll=max(ll, lg), rr=min(rr, rg);
            if(ll<=rr)
            {
                unsigned long long add=mask[rr-ll];
                if((b<<6)<lg) add<<=(lg-(b<<6));
                va[r][b]^=add;
            }
            q[r]+=__builtin_popcountll(va[r][b]);
        }

        pos[r]=se.insert({q[r], r}).first;

        pr=fpr(pos[r]), ne=fne(pos[r]);

        if(pr!=-1 and iter[pr]!=us.end()) us.erase(iter[pr]), iter[pr]=us.end();

        if(pr!=-1) check(pr, r);
        if(ne!=-1) check(r, ne);

        if(us.size())
        {
            int i=*us.begin(), j, y1=-1, y2=-1;
            auto it=pos[i];
            it++;
            j=(*it).second;
            for(int b=0; b<sz2; b++)
            {
                if(y1==-1 and ((va[i][b]&va[j][b])!=va[i][b]))
                {
                    for(int c=0; c<64; c++)
                    {
                        if((va[i][b]&one[c]) and (va[j][b]&one[c])==0)
                        {
                            y1=(b<<6)+c;
                            break;
                        }
                    }
                }
                if(y2==-1 and ((va[i][b]&va[j][b])!=va[j][b]))
                {
                    for(int c=0; c<64; c++)
                    {
                        if((va[j][b]&one[c]) and (va[i][b]&one[c])==0)
                        {
                            y2=(b<<6)+c;
                            break;
                        }
                    }
                }
            }
            if(i>j) swap(i, j);
            if(y1>y2) swap(y1, y2);
            printf("%d %d %d %d\n", i+1, y1+1, j+1, y2+1);
        }
        else printf("-1\n");
    }
}