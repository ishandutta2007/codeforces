#include <bits/stdc++.h>
#define iter set <pair <int, int> >::iterator
using namespace std;
const int sz=1e5+10;
int co[sz][10][2], si[sz], q=0;
set <pair <int, int> > l[10], r[10];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        int cl[k], cr[k];
        for(int b=0; b<k; b++)
        {
            scanf("%d", &cl[b]), cr[b]=cl[b];
        }
        for(int b=0; b<k; b++)
        {
            iter it=r[b].upper_bound(make_pair(cl[b], 2e9));
            if(it!=r[b].end())
            {
                int nu=(*it).second;
                for(int c=0; c<k; c++) cl[c]=min(cl[c], co[nu][c][0]);
            }
            it=l[b].upper_bound(make_pair(cr[b], 2e9));
            if(it!=l[b].begin())
            {
                it--;
                int nu=(*it).second;
                for(int c=0; c<k; c++) cr[c]=max(cr[c], co[nu][c][1]);
            }
        }
        for(int b=0; b<k; b++)
        {
            si[q]=1;
            iter st=l[b].lower_bound(make_pair(cl[b], 0));
            iter it=st;
            while(it!=l[b].end())
            {
                if((*it).first>cr[b]) break;
                else
                {
                    si[q]+=si[(*it).second], it++;
                }
            }
            l[b].erase(st, it);
            l[b].insert(make_pair(cl[b], q));
            co[q][b][0]=cl[b];
            st=r[b].lower_bound(make_pair(cl[b], 0));
            it=st;
            while(it!=r[b].end())
            {
                if((*it).first>cr[b]) break;
                else it++;
            }
            r[b].erase(st, it);
            r[b].insert(make_pair(cr[b], q));
            co[q][b][1]=cr[b];
        }
        q++;
        iter it=l[0].end();
        it--;
        printf("%d\n", si[(*it).second]);
    }
}