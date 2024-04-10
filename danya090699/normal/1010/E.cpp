#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
int dot[2][2][sz*4];
void recalc(int nu, int i, int j)
{
    dot[i][j][nu]=max(dot[i][j][nu*2], dot[i][j][nu*2+1]);
}
int p, va;
void cha(int nu, int l, int r, int i, int j)
{
    if(l==r) dot[i][j][nu]=va;
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid, i, j);
        else cha(nu*2+1, mid+1, r, i, j);
        recalc(nu, i, j);
    }
}
int lg, rg;
int quer(int nu, int l, int r, int i, int j)
{
    if(l>=lg and r<=rg) return dot[i][j][nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return max(quer(nu*2, l, mid, i, j), quer(nu*2+1, mid+1, r, i, j));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int q[3], n, m, k;
    cin>>q[0]>>q[1]>>q[2]>>n>>m>>k;
    int l[3]={inf, inf, inf}, r[3]={-inf, -inf, -inf};
    for(int a=0; a<n; a++)
    {
        for(int i=0; i<3; i++)
        {
            int x;
            scanf("%d", &x);
            l[i]=min(l[i], x), r[i]=max(r[i], x);
        }
    }
    int bad[m][3][2], er=0;
    vector <int> pref[q[0]+1], suf[q[0]+1], zap[q[0]+1];
    map <pair <int, int>, int> ma[2][2];
    for(int a=0; a<m; a++)
    {
        int okq=0;
        for(int i=0; i<3; i++)
        {
            int x;
            scanf("%d", &x);
            if(x<l[i])
            {
                bad[a][i][0]=x, bad[a][i][1]=0;
            }
            else if(x>r[i])
            {
                bad[a][i][0]=0, bad[a][i][1]=q[i]-x+1;
            }
            else
            {
                bad[a][i][0]=q[i], bad[a][i][1]=0, okq++;
            }
        }
        if(okq==3) er=1;
        if(bad[a][0][0]) pref[bad[a][0][0]].push_back(a);
        else suf[bad[a][0][1]].push_back(a);
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                if(bad[a][1][i] and bad[a][2][j]) ma[i][j][make_pair(bad[a][1][i], a)]=0;
            }
        }
    }
    if(er) cout<<"INCORRECT";
    else
    {
        int si[2][2];
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                ma[i][j][make_pair(inf, -1)]=0;
                si[i][j]=0;
                for(auto it=ma[i][j].begin(); it!=ma[i][j].end(); it++)
                {
                    (*it).second=si[i][j], si[i][j]++;
                }
            }
        }
        int que[k][3];
        for(int a=0; a<k; a++)
        {
            for(int i=0; i<3; i++) scanf("%d", &que[a][i]);
            zap[que[a][0]].push_back(a);
        }
        for(int a=0; a<m; a++)
        {
            if(bad[a][0][0])
            {
                for(int i=0; i<2; i++)
                {
                    for(int j=0; j<2; j++)
                    {
                        if(bad[a][1][i] and bad[a][2][j])
                        {
                            p=ma[i][j][make_pair(bad[a][1][i], a)], va=bad[a][2][j];
                            cha(1, 0, si[i][j]-1, i, j);
                        }
                    }
                }
            }
        }
        int an[k];
        for(int a=1; a<=q[0]; a++)
        {
            for(int b=0; b<suf[q[0]-a+1].size(); b++)
            {
                int nu=suf[q[0]-a+1][b];
                for(int i=0; i<2; i++)
                {
                    for(int j=0; j<2; j++)
                    {
                        if(bad[nu][1][i] and bad[nu][2][j])
                        {
                            p=ma[i][j][make_pair(bad[nu][1][i], nu)], va=bad[nu][2][j];
                            cha(1, 0, si[i][j]-1, i, j);
                        }
                    }
                }
            }

            for(int b=0; b<zap[a].size(); b++)
            {
                int nu=zap[a][b], good=1;
                for(int i=0; i<3; i++)
                {
                    if(que[nu][i]<l[i] or que[nu][i]>r[i]) good=0;
                }
                if(good) an[nu]=1;
                else
                {
                    an[nu]=0;
                    for(int i=0; i<2; i++)
                    {
                        int x=que[nu][1];
                        if(i) x=q[1]-x+1;
                        for(int j=0; j<2; j++)
                        {
                            int y=que[nu][2];
                            if(j) y=q[2]-y+1;

                            auto it=ma[i][j].lower_bound(make_pair(x, -1));
                            lg=(*it).second, rg=si[i][j]-1;
                            int re=quer(1, 0, si[i][j]-1, i, j);
                            if(re>=y) an[nu]=-1;
                        }
                    }
                }
            }

            for(int b=0; b<pref[a].size(); b++)
            {
                int nu=pref[a][b];
                for(int i=0; i<2; i++)
                {
                    for(int j=0; j<2; j++)
                    {
                        if(bad[nu][1][i] and bad[nu][2][j])
                        {
                            p=ma[i][j][make_pair(bad[nu][1][i], nu)], va=0;
                            cha(1, 0, si[i][j]-1, i, j);
                        }
                    }
                }
            }
        }
        cout<<"CORRECT\n";
        for(int a=0; a<k; a++)
        {
            if(an[a]==1) printf("OPEN\n");
            if(an[a]==0) printf("UNKNOWN\n");
            if(an[a]==-1) printf("CLOSED\n");
        }
    }
}