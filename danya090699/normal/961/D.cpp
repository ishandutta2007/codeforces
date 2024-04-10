#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    if(n<5) cout<<"YES";
    else
    {
        int ar[n][2];
        for(int a=0; a<n; a++) scanf("%lld%lld", &ar[a][0], &ar[a][1]);
        int a1, b1, c1, fo=0;
        for(int a=1; a<n; a++)
        {
            a1=ar[0][1]-ar[a][1], b1=ar[a][0]-ar[0][0], c1=-a1*ar[0][0]-b1*ar[0][1];
            vector <int> sp;
            for(int b=1; b<n; b++)
            {
                if(a!=b)
                {
                    if(ar[b][0]*a1+ar[b][1]*b1+c1==0)
                    {
                        fo=1;
                        break;
                    }
                    else
                    {
                        if(sp.size()<2) sp.push_back(b);
                        else
                        {
                            int u=sp[0], v=sp[1];
                            a1=ar[u][1]-ar[v][1], b1=ar[v][0]-ar[u][0], c1=-a1*ar[u][0]-b1*ar[u][1];
                            if(ar[b][0]*a1+ar[b][1]*b1+c1==0) fo=1;
                            break;
                        }
                    }
                }
            }
            if(fo) break;
        }
        vector <int> sp;
        for(int a=0; a<n; a++)
        {
            if(ar[a][0]*a1+ar[a][1]*b1+c1!=0) sp.push_back(a);
        }
        if(sp.size()>2)
        {
            int u=sp[0], v=sp[1], ok=1;
            a1=ar[u][1]-ar[v][1], b1=ar[v][0]-ar[u][0], c1=-a1*ar[u][0]-b1*ar[u][1];
            for(int a=0; a<sp.size(); a++)
            {
                if(ar[sp[a]][0]*a1+ar[sp[a]][1]*b1+c1!=0) ok=0;
            }
            if(ok) cout<<"YES";
            else cout<<"NO";
        }
        else cout<<"YES";
    }
}