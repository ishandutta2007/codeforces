#include <bits/stdc++.h>
using namespace std;
const int inf=1e9, sz=1e5+10;
struct el
{
    int su=0;
    el *l=0, *r=0;
};
map <string, int> ma;
el *dot[sz], *dot2[sz];
int lg, rg, p, add, ty;
void recalc(el &tr)
{
    tr.su=0;
    if(tr.l!=0) tr.su+=(*tr.l).su;
    if(tr.r!=0) tr.su+=(*tr.r).su;
}
el* cha(el &tr, int l, int r)
{
    el *ntr=new el;
    *ntr=tr;
    if(l==r)
    {
        if(ty==1) (*ntr).su=add;
        else (*ntr).su+=add;
    }
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid)
        {
            if(tr.l==0) tr.l=new el;
            (*ntr).l=cha(*tr.l, l, mid);
        }
        else
        {
            if(tr.r==0) tr.r=new el;
            (*ntr).r=cha(*tr.r, mid+1, r);
        }
        recalc(tr), recalc(*ntr);
    }
    return ntr;
}
int que(el &tr, int l, int r)
{
    if(l>=lg and r<=rg) return tr.su;
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        if(tr.l==0) tr.l=new el;
        if(tr.r==0) tr.r=new el;
        return que(*tr.l, l, mid)+que(*tr.r, mid+1, r);
    }
}
void ins(string name, int va, int i)
{
    lg=ma[name], rg=lg;
    p=que(*dot2[i], 0, sz), add=-1, ty=2;
    if(p>0) dot[i]=cha(*dot[i], 0, inf);

    p=ma[name], add=va, ty=1;
    dot2[i]=cha(*dot2[i], 0, sz);
    p=va, add=1, ty=2;
    if(p>0) dot[i]=cha(*dot[i], 0, inf);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    dot[0]=new el, dot2[0]=new el;
    for(int a=0; a<q; a++)
    {
        dot[a+1]=dot[a], dot2[a+1]=dot2[a];
        string type, name;
        int x;
        cin>>type;
        if(type=="set")
        {
            cin>>name>>x;
            if(ma.find(name)==ma.end()) ma[name]=ma.size()-1;
            ins(name, x, a+1);
        }
        if(type=="remove")
        {
            cin>>name;
            if(ma.find(name)==ma.end()) ma[name]=ma.size()-1;
            ins(name, 0, a+1);
        }
        if(type=="query")
        {
            cin>>name;
            if(ma.find(name)==ma.end()) ma[name]=ma.size()-1;
            lg=ma[name], rg=lg;
            p=que(*dot2[a+1], 0, sz);
            if(p==0) cout<<"-1\n";
            else
            {
                lg=0, rg=p-1;
                int an=que(*dot[a+1], 0, inf);
                cout<<an<<"\n";
            }
        }
        if(type=="undo")
        {
            int d;
            cin>>d;
            dot[a+1]=dot[a-d], dot2[a+1]=dot2[a-d];
        }
    }
}