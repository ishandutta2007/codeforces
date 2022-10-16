#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
#define POVAR 1488228228
#define X first
#define Y second
using namespace std;

vector<string>q;
vector<int>ql;
pair<int, int>ans[1500100];
pair<pair<int, int>, int>h[1500100];
map<string, int>cd;
vector<int>gr[1500100];
bool was[1500100];
int n, m, it=0;
char ss[800100], ff[800100];
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", ss);
        int l = strlen(ss), r = 0;
        for (int j=0; j<l; j++)
        {
            if ( ss[j]>='A' && ss[j]<='Z' )
                ss[j] = ss[j] - 'A' + 'a';
            if ( ss[j] == 'r' ) r++;
        }
        q.pb( ss );
        if ( cd.find(q.back())==cd.end() ) 
        {
            it++, cd[q.back()] = it;
            h[it].Y = it;
            h[it].X = mp(r, l);
        }
    }
    scanf("%d", &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%s%s", ss, ff);
        int l1 = strlen(ss), r1 = 0;
        for (int j=0; j<l1; j++)
        {
            if ( ss[j]>='A' && ss[j]<='Z' )
                ss[j] = ss[j] - 'A' + 'a';
            if ( ss[j] == 'r' ) r1++;
        }
        q.pb( ss );
        if ( cd.find(q.back())==cd.end() ) 
        {
            it++, cd[q.back()] = it;
            h[it].X = mp(r1, l1); 
            h[it].Y = it;
        }
        int l2=strlen(ff), r2 = 0;
        for (int j=0; j<l2; j++)
        {
            if ( ff[j]>='A' && ff[j]<='Z' )
                ff[j] = ff[j] - 'A' + 'a';
            if ( ff[j] == 'r' ) r2++;
        }
        q.pb( ff );
        if ( cd.find(q.back())==cd.end() ) 
        {
            it++, cd[q.back()] = it;
            h[it].X = mp(r2, l2); 
            h[it].Y = it;
        }
        gr[cd[ff]].pb( cd[ss] );
    }
    sort(h+1, h+it+1);
    for (int i=1; i<=it; i++)
    {
        if ( was[ h[i].Y ] ) continue;
        ql.clear();
        ql.pb( h[i].Y );
        was[ h[i].Y ] = true;
        int st = 0;
        while ( st<ql.size() )
        {
            int x = ql[st];
            st++;
            ans[x] = h[i].X;
            for (int i=0; i<gr[x].size(); i++)
            {
                int to = gr[x][i];
                if ( was[to]==false )
                {
                    was[to]=1;
                    ql.pb(to);
                }
            } 
        }
    }
    pair<int228, int228>res = mp(0, 0);
    
    for (int i=0; i<n; i++)
    {
        res.X += ans[cd[ q[i] ] ].X;
        res.Y += ans[cd[ q[i] ] ].Y;
    }
    cout<<res.X<<" "<<res.Y<<endl;
    return 228/1488;
}