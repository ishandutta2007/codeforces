//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int de(int a, int b)
{
    int re=a/b;
    if(a%b>0) re++;
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    long long k, qsu=0, ossu=0, an;
    cin>>n>>k;
    int ar[n], ple[n];
    vector <pair <int, int> > ve;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ple[a]=-1;
        for(int b=1; b<=ar[a]; b++)
        {
            int x=de(ar[a], b);
            if(x<b) break;
            ve.push_back(make_pair(b, a));
            ve.push_back(make_pair(x, a));
        }
    }
    sort(ve.begin(), ve.end());
    int yk=0;
    while(yk<ve.size())
    {
        int cu=ve[yk].first;
        while(yk<ve.size())
        {
            if(ve[yk].first==cu)
            {
                int nu=ve[yk].second;
                if(ple[nu]!=-1)
                {
                    int pq=de(ar[nu], ple[nu]);
                    int pos=(ple[nu]*pq)-ar[nu];
                    qsu-=pq, ossu-=pos+1ll*(cu-ple[nu])*pq;
                }
                int q=de(ar[nu], cu);
                int os=(cu*q)-ar[nu];
                qsu+=q, ossu+=os;
                ple[nu]=cu;
                yk++;
            }
            else break;
        }
        if(ossu<=k)
        {
            long long add=(k-ossu)/qsu;
            an=cu+add;
        }
        if(yk!=ve.size())
        {
            int ne=ve[yk].first;
            ossu+=qsu*(ne-cu);
        }
    }
    cout<<an;
}