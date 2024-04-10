//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
bool comp(int *a, int *b){return a[0]>b[0];}
int h, w, n, mod=1e9+7, lg, rg, x, cnu, an, su;
int de[sz*4][3];
vector <int> dot[sz*4];
void add(int nu, int l, int r)
{
    dot[nu].push_back(x);
    if(l!=r)
    {
        int mid=(l+r)/2;
        if(lg<=mid) add(nu*2, l, mid);
        else add(nu*2+1, mid+1, r);
    }
}
void que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        while(dot[nu].size()!=0)
        {
            int cu=dot[nu].back();
            if(de[cu][2]==0) dot[nu].pop_back();
            else
            {
                if(de[cu][0]>x) break;
                else
                {
                    su+=de[cu][1], de[cu][2]=0;
                    if(su>mod) su-=mod;
                    dot[nu].pop_back();
                }
            }
        }
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        que(nu*2, l, mid);
        que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>h>>w>>n;
    int *ar[n];
    for(int a=0; a<n; a++)
    {
        ar[a]=new int[4];
        for(int b=0; b<4; b++) scanf("%d", &ar[a][b]);
    }
    sort(ar, ar+n, comp);
    for(int a=0; a<w; a++)
    {
        de[a][0]=h+1, de[a][1]=1, de[a][2]=1;
        x=a, lg=a, add(1, 0, w-1);
    }
    cnu=w, an=w;
    for(int a=0; a<n; a++)
    {
        lg=ar[a][1]-1, rg=ar[a][2]-1, x=ar[a][0]+ar[a][3];
        su=0, que(1, 0, w-1);
        an+=su;
        if(an>mod) an-=mod;
        de[cnu][0]=ar[a][0], de[cnu][1]=su, de[cnu][2]=1, x=cnu, cnu++;
        lg=ar[a][1]-2;
        if(lg==-1) lg=ar[a][2];
        add(1, 0, w-1);
        de[cnu][0]=ar[a][0], de[cnu][1]=su, de[cnu][2]=1, x=cnu, cnu++;
        lg=ar[a][2];
        if(lg==w) lg=ar[a][1]-2;
        add(1, 0, w-1);
    }
    cout<<an;
}