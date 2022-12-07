#include <bits/stdc++.h>
using namespace std;
const int sz=10800, sz2=60;
int an[sz][4], q=0;
int fi[sz2][sz2], cu[sz2][2], to[sz2][2], col[sz2];
void add(int i, int dx, int dy)
{
    fi[cu[i][0]][cu[i][1]]=-1;
    an[q][0]=cu[i][0], an[q][1]=cu[i][1];
    cu[i][0]+=dx, cu[i][1]+=dy;
    an[q][2]=cu[i][0], an[q][3]=cu[i][1];
    fi[cu[i][0]][cu[i][1]]=i;
    q++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    if(n==1) cout<<0;
    else
    {
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) fi[a][b]=-1;
    for(int a=0; a<m; a++)
    {
        cin>>cu[a][0]>>cu[a][1];
        cu[a][0]--, cu[a][1]--;
        fi[cu[a][0]][cu[a][1]]=a;
    }
    for(int a=0; a<m; a++)
    {
        cin>>to[a][0]>>to[a][1];
        to[a][0]--, to[a][1]--;
        col[to[a][1]]++;
    }
    int us=0, be=0;
    for(int a=1; a+1<n; a++) if(col[a]+col[a+1]<col[be]+col[be+1]) be=a;
    for(int a=0; a<n; a++)
    {
        int i=fi[a][be];
        if(i!=-1)
        {
            while(cu[i][0]>us) add(i, -1, 0);
            us++;
        }
    }
    for(int a=be-1; a>=0; a--)
    {
        for(int b=n-1; b>=0; b--)
        {
            int i=fi[b][a];
            if(i!=-1)
            {
                while(cu[i][0]<us) add(i, 1, 0);
                while(cu[i][1]<be) add(i, 0, 1);
                while(cu[i][0]>us) add(i, -1, 0);
                us++;
            }
        }
    }
    for(int a=be+1; a<n; a++)
    {
        for(int b=n-1; b>=0; b--)
        {
            int i=fi[b][a];
            if(i!=-1)
            {
                while(cu[i][0]<us) add(i, 1, 0);
                while(cu[i][1]>be) add(i, 0, -1);
                while(cu[i][0]>us) add(i, -1, 0);
                us++;
            }
        }
    }
    for(int a=n-1; a>be+1; a--)
    {
        for(int i=0; i<m; i++)
        {
            if(to[i][1]==a and cu[i][1]==be)
            {
                add(i, 0, 1);
                while(cu[i][0]>to[i][0]) add(i, -1, 0);
                while(cu[i][0]<to[i][0]) add(i, 1, 0);
                while(cu[i][1]<to[i][1]) add(i, 0, 1);
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        int i=fi[a][be];
        if(i!=-1) add(i, 0, 1);
    }
    for(int a=0; a<be; a++)
    {
        for(int i=0; i<m; i++)
        {
            if(to[i][1]==a and cu[i][1]==be+1)
            {
                add(i, 0, -1);
                while(cu[i][0]>to[i][0]) add(i, -1, 0);
                while(cu[i][0]<to[i][0]) add(i, 1, 0);
                while(cu[i][1]>to[i][1]) add(i, 0, -1);
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        int i=fi[a][be+1];
        if(i!=-1)
        {
            if(to[i][1]==be) add(i, 0, -1);
        }
    }
    for(int a=be; a<=be+1; a++)
    {
        for(int b=0; b<n; b++)
        {
            int i=fi[b][a];
            if(i!=-1)
            {
                for(int c=b-1; c>=0; c--)
                {
                    if(fi[c][a]==-1) add(i, -1, 0);
                }
            }
        }
    }
    if(fi[1][be]!=-1)
    {
        int i=fi[0][be], j=fi[1][be];
        if(to[i][0]>to[j][0])
        {
            add(i, 0, 1), add(i, 1, 0), add(j, -1, 0), add(i, 0, -1);
        }
    }
    if(fi[1][be+1]!=-1)
    {
        int i=fi[0][be+1], j=fi[1][be+1];
        if(to[i][0]>to[j][0])
        {
            add(i, 0, -1), add(i, 1, 0), add(j, -1, 0), add(i, 0, 1);
        }
    }
    for(int a=be; a<=be+1; a++)
    {
        for(int b=n-1; b>=0; b--)
        {
            int i=fi[b][a];
            if(i!=-1)
            {
                while(cu[i][0]<to[i][0]) add(i, 1, 0);
            }
        }
    }
    cout<<q<<"\n";
    for(int a=0; a<q; a++)
    {
        for(int b=0; b<4; b++) printf("%d ", an[a][b]+1);
        printf("\n");
    }
    }
}