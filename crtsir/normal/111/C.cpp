#include<bits/stdc++.h>
using namespace std;
bool a[41][41];
int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1},n,m,best;
void search(int x)
{
    bool ok=1;
    int i,j;
    vector<pair<int,int> >tmp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(a[i][j]==0)
            {
                ok=0;
                break;
            }
        if(!ok)
            break;
    }
    if(ok){
        best=x;
        return;
    }
    if(x+1>=best)return;
    int xx=i,yy=j;
    for(i=0;i<5;i++)
    {
        int x2=dx[i]+xx,y2=dy[i]+yy;
        if(x2>=0&&x2<n&&y2>=0&&y2<m)
        {
            tmp.clear();
            for(j=0;j<5;j++)
                if(x2+dx[j]>=0&&x2+dx[j]<n)
                    if(y2+dy[j]>=0&&y2+dy[j]<m)
                        if(a[x2+dx[j]][y2+dy[j]]==0)
                            a[x2+dx[j]][y2+dy[j]]=1,
                            tmp.push_back(make_pair(x2+dx[j],y2+dy[j]));
            search(x+1);
            for(j=0;j<tmp.size();j++)
                a[tmp[j].first][tmp[j].second]=0;
        }
    }
}
int main()
{
    memset(a,0,sizeof(a));
    cin>>n>>m;
    best=n*m;
    search(0);
    cout<<n*m-best;
}