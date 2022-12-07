#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int ar[sz], zap[sz][2], an[sz], basl[sz][20], basr[sz][20];
void copy(int *A, int *B)
{
    for(int a=0; a<20; a++) B[a]=A[a];
}
void add(int *A, int x)
{
    for(int i=19; i>=0; i--)
    {
        if(x&(1<<i))
        {
            if(A[i]&(1<<i)) x^=A[i];
            else
            {
                A[i]=x;
                break;
            }
        }
    }
}
void dfs(int l, int r, vector <int> &sp)
{
        int mid=(l+r)>>1;
        for(int a=mid; a>=l; a--)
        {
            copy(basl[mid-a], basl[mid-a+1]);
            add(basl[mid-a+1], ar[a]);
        }
        for(int a=mid+1; a<=r; a++)
        {
            copy(basr[a-mid-1], basr[a-mid]);
            add(basr[a-mid], ar[a]);
        }
        vector <int> spl, spr;
        for(int a=0; a<sp.size(); a++)
        {
            int nu=sp[a];
            int lg=zap[nu][0], rg=zap[nu][1];
            if(lg>mid+1) spr.push_back(nu);
            else if(rg<mid) spl.push_back(nu);
            else
            {
                int li=mid+1-lg, ri=rg-mid, cubas[20];
                for(int i=0; i<20; i++) cubas[i]=0;
                for(int i=0; i<20; i++) add(cubas, basl[li][i]);
                for(int i=0; i<20; i++) add(cubas, basr[ri][i]);
                an[nu]=0;
                for(int i=19; i>=0; i--)
                {
                    if((an[nu]&(1<<i))==0)
                    {
                        if(cubas[i]&(1<<i)) an[nu]^=cubas[i];
                    }
                }
            }
        }
        sp.clear();
        if(l!=r)
        {
            dfs(l, mid, spl);
            dfs(mid+1, r, spr);
        }

}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    cin>>q;
    vector <int> sp;
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &zap[a][0], &zap[a][1]);
        zap[a][0]--, zap[a][1]--;
        sp.push_back(a);
    }
    dfs(0, n-1, sp);
    for(int a=0; a<q; a++) printf("%d\n", an[a]);
}