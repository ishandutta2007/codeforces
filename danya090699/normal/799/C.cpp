#include <bits/stdc++.h>
using namespace std;
bool comp(int *a, int *b){return (a[1]<b[1]);}
int *dot[2], lg, rg, nva;
vector <int*> fo[2];
void recalc(int nu, int ty)
{
    dot[ty][nu]=max(dot[ty][nu*2], dot[ty][nu*2+1]);
}
void build(int nu, int l, int r, int ty)
{
    if(l==r) dot[ty][nu]=fo[ty][l][0];
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid, ty);
        build(nu*2+1, mid+1, r, ty);
        recalc(nu, ty);
    }
}
void cha(int nu, int l, int r, int ty)
{
    if(lg==l)
    {
        dot[ty][nu]=nva;
        //cout<<nva<<" "<<lg<<"\n";
    }

    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) cha(nu*2, l, mid, ty);
        else cha(nu*2+1, mid+1, r, ty);
        recalc(nu, ty);
    }
}
int que(int nu, int l, int r, int ty)
{
    if(l>=lg and r<=rg) return dot[ty][nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        return max(que(nu*2, l, mid, ty), que(nu*2+1, mid+1, r, ty));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, c, d, best=0;
    cin>>n>>c>>d;
    for(int a=0; a<n; a++)
    {
        int bea, pr;
        char ty;
        cin>>bea>>pr>>ty;
        int *nel=new int[2];
        nel[0]=bea, nel[1]=pr;
        if(ty=='C') fo[0].push_back(nel);
        else fo[1].push_back(nel);
    }
    for(int a=0; a<2; a++) sort(fo[a].begin(), fo[a].end(), comp);
    int be[2];
    be[0]=0, be[1]=0;
    for(int a=0; a<2; a++)
    {
        if(fo[a].size()>0)
        {
            //cout<<a<<" ";
            dot[a]=new int[fo[a].size()*4];
            build(1, 0, fo[a].size()-1, a);
            for(int b=0; b<fo[a].size(); b++)
            {
                lg=b, nva=0;

                cha(1, 0, fo[a].size()-1, a);
                //if(a==1) cout<<nva<<" ";
                int ha=c;
                if(a==1) ha=d;
                int *nel=new int[2];
                nel[1]=ha-fo[a][b][1];
                rg=upper_bound(fo[a].begin(), fo[a].end(), nel, comp)-fo[a].begin();
                lg=0, rg--;

                if(rg>=lg)
                {
                    int an=que(1, 0, fo[a].size()-1, a);
                    if(an!=0) best=max(best, fo[a][b][0]+an);

                }
                lg=b, nva=fo[a][b][0];
                cha(1, 0, fo[a].size()-1, a);
                if(nel[1]>=0) be[a]=max(be[a], fo[a][b][0]);
            }
        }
    }
    //cout<<best<<" ";
    if(be[0]>0 and be[1]>0) best=max(best, be[0]+be[1]);
    cout<<best;

}