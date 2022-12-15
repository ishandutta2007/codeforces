#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-4;
const ll INF=ll(1e18);
const int sINF=int(1e9);
typedef pair<int,int> ii;
typedef map<int,int>::iterator mpit;
typedef long long ll;
using namespace std;

int n;
vector<int> d,a[3];

int main()
{
    cin>>n;
    d.resize(n);
    int ne=0;
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        if(d[i]<0)ne++;
    }
    bool b=1;
    ne=(ne>=3?2:0);
    for(int i=0;i<n;i++)
    {
        if(d[i]<0)
        {
            if(b)
            {
                a[0].push_back(d[i]);
                b=0;
            }
            else
            {
                if(ne)
                {
                    a[1].push_back(d[i]);
                    ne--;
                }
                else a[2].push_back(d[i]);
            }
        }
        else if(d[i]==0)
        {
            a[2].push_back(d[i]);
        }
        else
        {
            a[1].push_back(d[i]);
        }
    }
    for(int i=0;i<3;i++)
    {
        cout<<a[i].size();
        for(int j=0;j<a[i].size();j++)cout<<" "<<a[i][j];
        cout<<endl;
    }
}