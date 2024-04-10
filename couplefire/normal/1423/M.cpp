#include<bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int ans = INT_MAX,N,M,pos[MAXN];
int query(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int val;scanf("%d",&val);
    return val;
}
void go(vector<int>row,vector<int>col)
{
    int n = (int)row.size(),m = (int)col.size();
    if(n==1)
    {
        int minn = INT_MAX;
        for(int i=0;i<m;i++)
        {
            int temp = query(row[0],col[i]);
            if(minn>temp)minn = temp,pos[row[0]] = col[i];
        }
        ans = min(ans,minn);
        return;
    }
    if(n<m)
    {
        vector<int>scol;
        int j = 0, r;
        for(int i=0;i<(int)col.size();i++){
            int c = col[i];
            if(scol.empty()){scol.push_back(c);continue;}
            r = row[j];
            int y = scol.back();
            while(query(r, y) > query(r, c))
            {
                scol.pop_back();--j;
                if(scol.empty()) break;
                r = row[j];
                y = scol.back();
            }
            if((int)scol.size()!=n)
            {
                scol.push_back(c);++j;
            }
        }
        col = scol;
        m = scol.size();
    }
    vector<int>srow;
    for(int i=1;i<n;i+=2)srow.push_back(row[i]);
    go(srow,col);
    for(int i=0;i<n;i+=2)
    {
        int id = row[i],l = 1,r = M,minn = INT_MAX;
        if(i>0)l = pos[row[i-1]];
        if(i+1<n)r = pos[row[i+1]];
        l = lower_bound(col.begin(),col.end(),l) - col.begin();
        r = upper_bound(col.begin(),col.end(),r) - col.begin() - 1;
        for(int j=l;j<=r;j++)
        {
            int temp = query(id,col[j]);
            if(minn>temp)minn = temp,pos[id] = col[j];
        }
        ans = min(ans,minn);
    }
}
int main()
{
    scanf("%d %d",&N,&M);
    vector<int>row,col;
    pos[0] = 1,pos[N+1] = M;
    for(int i=1;i<=N;i++)row.push_back(i);
    for(int j=1;j<=M;j++)col.push_back(j);
    go(row,col);
    printf("! %d\n",ans);
    fflush(stdout);
    return 0;
}