#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, a[100000], inf, m, l, r;
long long k;
vector <int> lev;
vector <int> prav;

int main()
{
    inf=1000000000;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<100001;i++)
    {
        lev.push_back(inf);
        prav.push_back(-inf);
    }
    for(int i=0;i<n;i++)
    {
        lev[a[i]]=min(lev[a[i]], i);
        prav[a[i]]=max(prav[a[i]], i);
    }
    sort(lev.begin(), lev.end());
    for(int i=0;i<100001;i++)
    {
        l=-1;
        r=100001;
        while(r-l>1)
        {
            m=(l+r)/2;
            if(lev[m]<prav[i])
                l=m;
            else r=m;
        }
        k=k+l+1;
    }
    cout << k;
    return 0;
}