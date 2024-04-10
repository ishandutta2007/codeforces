#include <bits/stdc++.h>
#define iter map <int, vector <int> >::iterator
using namespace std;
const int sz=5e5+10;
int an[sz][3], anq=0;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q=0;
    cin>>n>>m;
    int si[n];
    set <int> se[n];
    map <int, vector <int> > ma;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &si[a]);
        q+=si[a];
        for(int b=0; b<si[a]; b++)
        {
            int x;
            scanf("%d", &x);
            x--;
            se[a].insert(x);
            ma[x].push_back(a);
        }
    }

    int mi=q/n, os=(q%n>0);


    for(int a=0; a<n; a++)
    {
        if(si[a]<mi)
        {
            vector <iter> del;
            for(auto it=ma.begin(); it!=ma.end(); it++)
            {
                int x=(*it).first;
                vector <int> &ve=(*it).second;
                if(se[a].find(x)==se[a].end())
                {
                    while(ve.size())
                    {
                        int nu=ve.back();
                        if(si[nu]>mi+os)
                        {
                            an[anq][0]=nu, an[anq][1]=a, an[anq][2]=x, anq++;
                            si[nu]--, si[a]++;
                            ve.pop_back();
                            break;
                        }
                        else ve.pop_back();
                    }
                }
                if(ve.size()==0) del.push_back(it);

                if(si[a]==mi) break;
            }
            while(del.size())
            {
                ma.erase(del.back()), del.pop_back();
            }
        }
    }
    int badq=0;
    for(int a=0; a<n; a++) if(si[a]>mi+os) badq++;
    for(int a=0; a<n; a++)
    {
        if(si[a]==mi and badq)
        {
            vector <iter> del;
            for(auto it=ma.begin(); it!=ma.end(); it++)
            {
                int x=(*it).first;
                vector <int> &ve=(*it).second;
                if(se[a].find(x)==se[a].end())
                {
                    while(ve.size())
                    {
                        int nu=ve.back();
                        if(si[nu]>mi+os)
                        {
                            an[anq][0]=nu, an[anq][1]=a, an[anq][2]=x, anq++;
                            si[nu]--, si[a]++;
                            if(si[nu]<mi+os) badq--;
                            ve.pop_back();
                            break;
                        }
                        else ve.pop_back();
                    }
                }
                if(ve.size()==0) del.push_back(it);

                if(si[a]==mi+1) break;
            }
            while(del.size())
            {
                ma.erase(del.back()), del.pop_back();
            }
        }
    }
    cout<<anq<<"\n";
    for(int a=0; a<anq; a++) printf("%d %d %d\n", an[a][0]+1, an[a][1]+1, an[a][2]+1);
}