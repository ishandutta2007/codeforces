#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, sz2=1e3;
vector <int> de[sz];
int tr[sz2][sz2];
int main()
{
    for(int a=0; a<sz2; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=tr[a-1][b-1]+tr[a-1][b];
    }

    for(int a=1; a<sz; a++)
    {
        for(int b=a; b<sz; b+=a) de[b].push_back(a);
    }

    set <pair <int, pair <int, int> > > masks;
    for(int a=1; a<8; a++)
    {
        for(int b=1; b<8; b++)
        {
            for(int c=1; c<8; c++)
            {
                if((a&1)>0 and (b&2)>0 and (c&4)>0)
                {
                    int ar[3]={a, b, c};
                    sort(ar, ar+3);
                    masks.insert(make_pair(ar[0], make_pair(ar[1], ar[2])));
                }
            }
        }
    }

    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        vector <int> te(de[x].size()+de[y].size());
        merge(de[x].begin(), de[x].end(), de[y].begin(), de[y].end(), te.begin());
        vector <int> sp(te.size()+de[z].size());
        merge(te.begin(), te.end(), de[z].begin(), de[z].end(), sp.begin());

        int q[8], an=0;
        for(int a=0; a<8; a++) q[a]=0;
        for(int a=0; a<sp.size(); a++)
        {
            int pr=0;
            if(a) pr=sp[a-1];
            if(sp[a]!=pr)
            {
                int mask=0;
                if(x%sp[a]==0) mask+=1;
                if(y%sp[a]==0) mask+=2;
                if(z%sp[a]==0) mask+=4;
                q[mask]++;
            }
        }

        for(auto it=masks.begin(); it!=masks.end(); it++)
        {
            int m1=(*it).first, m2=(*it).second.first, m3=(*it).second.second;
            if(q[m1] and q[m2] and q[m3])
            {
                if(m1==m2 and m2==m3) an+=tr[q[m1]-1+3][3];
                else if(m1==m2) an+=tr[q[m1]-1+2][2]*q[m3];
                else if(m2==m3) an+=tr[q[m2]-1+2][2]*q[m1];
                else an+=q[m1]*q[m2]*q[m3];
            }

        }

        printf("%d\n", an);
    }
}