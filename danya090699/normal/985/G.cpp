#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    unsigned long long n, m, x, y, z, an1=0, an2=0, an3=0, an=0;
    cin>>n>>m>>x>>y>>z;
    for(unsigned long long a=0; a<n; a++)
    {
        if(a+2<n) an+=(a*x)*((n-a-1)*(n-a-2)/2);
        if(a>0 and a+1<n) an+=(a*y)*(a*(n-a-1));
        if(a>1) an+=(a*z)*(a*(a-1)/2);
    }
    vector <int> sv[n];
    vector <unsigned long long> pref[n];
    for(unsigned long long a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(unsigned long long a=0; a<n; a++)
    {
        sort(sv[a].begin(), sv[a].end());
        pref[a].push_back(0);
        for(unsigned long long b=0; b<sv[a].size(); b++) pref[a].push_back(pref[a].back()+sv[a][b]);
    }
    for(unsigned long long v2=0; v2<n; v2++)
    {
        for(unsigned long long a=0; a<sv[v2].size(); a++)
        {
            unsigned long long u=sv[v2][a], v=v2;
            if(v<u)
            {
                unsigned long long l=v, r=u;
                if(sv[v].size()>sv[u].size()) swap(u, v);
                unsigned long long q[3][3], su[3][3];
                for(unsigned long long b=0; b<3; b++)
                {
                    for(unsigned long long c=0; c<3; c++)
                    {
                        q[b][c]=0, su[b][c]=0;
                    }
                }
                int pp=0;
                for(int b=0; b<sv[v].size(); b++)
                {
                    int i=sv[v][b], nu=3;
                    if(i<l) nu=0;
                    else if(i>l and i<r) nu=1;
                    else if(i>r) nu=2;

                    int st=min(pp+3, int(sv[u].size()));
                    while(pp<st)
                    {
                        if(sv[u][pp]<i) pp++;
                        else break;
                    }

                    bool fo=0;
                    if(pp!=sv[u].size())
                    {
                        if(sv[u][pp]<i) pp=lower_bound(sv[u].begin()+pp, sv[u].end(), i)-sv[u].begin();
                        if(pp!=sv[u].size())
                        {
                            if(sv[u][pp]==i) fo=1;
                        }
                    }

                    if(fo)
                    {
                        q[2][nu]++, su[2][nu]+=i;
                    }
                    else if(nu!=3)
                    {
                        q[1][nu]++, su[1][nu]+=i;
                    }
                }

                unsigned long long p=lower_bound(sv[u].begin(), sv[u].end(), l)-sv[u].begin();
                q[1][0]+=p-q[2][0], su[1][0]+=pref[u][p]-su[2][0];
                if(l>0)
                {
                    q[0][0]=l, su[0][0]=(l-1)*l/2;
                }
                q[0][0]-=q[1][0]+q[2][0], su[0][0]-=su[1][0]+su[2][0];

                p=upper_bound(sv[u].begin(), sv[u].end(), l)-sv[u].begin();
                unsigned long long p2=lower_bound(sv[u].begin(), sv[u].end(), r)-sv[u].begin();
                q[1][1]+=(p2-p)-q[2][1], su[1][1]+=(pref[u][p2]-pref[u][p])-su[2][1];
                if(r-l-1>0)
                {
                    q[0][1]=r-l-1, su[0][1]=((l+1)+(r-1))*(r-l-1)/2;
                }
                q[0][1]-=q[1][1]+q[2][1], su[0][1]-=su[1][1]+su[2][1];

                p=upper_bound(sv[u].begin(), sv[u].end(), r)-sv[u].begin(), p2=sv[u].size();
                q[1][2]+=(p2-p)-q[2][2], su[1][2]+=(pref[u][p2]-pref[u][p])-su[2][2];
                if(r<n-1)
                {
                    q[0][2]=n-1-r, su[0][2]=((r+1)+(n-1))*(n-1-r)/2;
                }
                q[0][2]-=q[1][2]+q[2][2], su[0][2]-=su[1][2]+su[2][2];

                an1+=su[0][0]*x+q[0][0]*(l*y+r*z);
                an1+=su[0][1]*y+q[0][1]*(l*x+r*z);
                an1+=su[0][2]*z+q[0][2]*(l*x+r*y);

                an2+=su[1][0]*x+q[1][0]*(l*y+r*z);
                an2+=su[1][1]*y+q[1][1]*(l*x+r*z);
                an2+=su[1][2]*z+q[1][2]*(l*x+r*y);

                an3+=su[2][2]*z+q[2][2]*(l*x+r*y);
            }
        }
    }
    cout<<an-(an1+an2/2+an3);
}