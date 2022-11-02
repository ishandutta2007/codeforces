#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > PII;
#define MAX 100
#define a first
#define b second
int n,m,k,Z[]={-1,0,0,1},z[]={0,-1,1,0};
char p[MAX][MAX];
void DFS(int x,int y,char who,char to)
{
    p[x][y]=to;
    for(int i=0;i<4;i++)
    {
        int qq=x+Z[i],ww=y+z[i];
        if(qq>=0 && qq<n && ww>=0 && ww<m)
        {
            if(p[qq][ww]==who)DFS(qq,ww,who,to);
        }
    }
}
int DDS(int x,int y)
{
    int ans=1;
    p[x][y]='@';
    for(int i=0;i<4;i++)
    {
        int qq=x+Z[i],ww=y+z[i];
        if(qq>=0 && qq<n && ww>=0 && ww<m && p[qq][ww]=='.')
            ans+=DDS(qq,ww);
    }
    return ans;
}
int main()
{

    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>p[i][j];
//            cout<<"E"<<endl;
        for(int i=0;i<n;i++)
        {
            if(p[i][0]=='.')DFS(i,0,'.','#');
            if(p[i][m-1]=='.')DFS(i,m-1,'.','#');
        }
        for(int i=0;i<m;i++)
        {
            if(p[0][i]=='.')DFS(0,i,'.','#');
            if(p[n-1][i]=='.')DFS(n-1,i,'.','#');
        }



        vector<PII> v;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(p[i][j]=='.')
                {
                    int e=DDS(i,j);//printf("e=%d\n",e);
                    v.push_back(make_pair(e,make_pair(i,j)));
                }
        sort(v.begin(),v.end());
        int x=int(v.size())-k,qans=0;
        for(int i=0;i<x;i++)
            DFS(v[i].b.a,v[i].b.b,'@','*'),qans+=v[i].a;

//        puts("");
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//                cout<<p[i][j];
//            cout<<endl;
//        }puts("");


        for(int i=0;i<n;i++)
        {
            if(p[i][0]=='#')DFS(i,0,'#','.');
            if(p[i][m-1]=='#')DFS(i,m-1,'#','.');
        }
        for(int i=0;i<m;i++)
        {
            if(p[0][i]=='#')DFS(0,i,'#','.');
            if(p[n-1][i]=='#')DFS(n-1,i,'#','.');
        }
        cout<<qans<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(p[i][j]=='@')cout<<'.';
                else cout<<p[i][j];
            cout<<endl;
        }
    }
    return 0;
}