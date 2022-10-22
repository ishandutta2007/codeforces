#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef pair<int,int> pii;

int arr[105][105],x,y,nans;
bool xs[105],ys[105];
pii ans[50005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,mi=501,sum=0;
    pii pos=pii(0,0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]<mi)
            {
                mi=arr[i][j];
                pos=pii(i,j);
            }
            if(arr[i][j]==0)
            {
                if(!xs[i])
                    xs[i]=true,x++;
                if(!ys[j])
                    ys[j]=true,y++;
            }
            sum+=arr[i][j];
        }

    if(sum && (x==n && y==m))
    {
        db(-1)
        return 0;
    }
    else if(!sum)
    {
        db(0)
        return 0;
    }
    else
    {
        while(sum && (x!=n || y!=m))
        {
            int mi1=501,mi2=501;
            for(int i=0;i<n;i++)
            {
                if(!xs[i])
                    for(int j=0;j<m;j++)
                    {
                        if(arr[i][j]<mi1)
                            mi1=arr[i][j];
                    }
            }

            for(int i=0;i<m;i++)
            {
                if(!ys[i])
                    for(int j=0;j<n;j++)
                    {
                        if(arr[j][i]<mi2)
                            mi2=arr[j][i];
                    }
            }

            if((m>n && mi1!=501) || mi2==501)
            {
                for(int i=0;i<n;i++)
                {
                    if(!xs[i])
                    {
                        for(int j=0;j<mi1;j++)
                            ans[nans++]=pii(1,i);
                        for(int j=0;j<m;j++)
                        {
                            sum-=mi1;
                            arr[i][j]-=mi1;
                            if(!arr[i][j])
                            {
                                if(!xs[i])
                                    xs[i]=true,x++;
                                if(!ys[j])
                                    ys[j]=true,y++;
                            }
                        }
                    }
                }
            }
            else
            {
                for(int i=0;i<m;i++)
                {
                    if(!ys[i])
                    {
                        for(int j=0;j<mi2;j++)
                            ans[nans++]=pii(2,i);
                        for(int j=0;j<n;j++)
                        {
                            sum-=mi2;
                            arr[j][i]-=mi2;
                            if(!arr[j][i])
                            {
                                if(!xs[j])
                                    xs[j]=true,x++;
                                if(!ys[i])
                                    ys[i]=true,y++;
                            }
                        }
                    }
                }
            }

//            for(int i=0;i<n;i++)
//            {
//                for(int j=0;j<m;j++)
//                    cout << arr[i][j] << ' ';
//                db("")
//            }
        }
        if(!sum)
        {
            db(nans)
            for(int i=0;i<nans;i++)
            {
                if(ans[i].first==1)
                    cout << "row " << ans[i].second+1 << '\n';
                else
                    cout << "col " << ans[i].second+1 << '\n';
            }
        }
        else
            db(-1)
    }

    return 0;
}
/**9 10

14 5 6 4 8 9 4 14 14 13

13 4 5 3 7 8 3 13 13 12

16 7 8 6 10 11 6 16 16 15

10 1 2 0 4 5 0 10 10 9

11 2 3 1 5 6 1 11 11 10

10 1 2 0 4 5 0 10 10 9

12 3 4 2 6 7 2 12 12 11

13 4 5 3 7 8 3 13 13 12

13 4 5 3 7 8 3 13 13 12**/