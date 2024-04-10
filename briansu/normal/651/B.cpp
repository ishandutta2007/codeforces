#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-4;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef map<int,int>::iterator mpit;
typedef long long ll;
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    int d[1001];
    memset(d,0,sizeof d);
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        d[tmp]++;
    }
    int cnt=0;
    while(n>0)
    {
        cnt--;
        for(int i=0;i<1001;i++)
        {
            if(d[i]>0)
            {
                cnt++;
                d[i]--;
                n--;
            }
        }
    }
    cout<<cnt<<endl;
}