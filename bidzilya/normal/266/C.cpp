#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1111;

int n;
int cStr[N], cStl[N], pst[N], x[N], y[N];
vector<int> atp,aa1,aa2;

void mSwap(int tp,int a1,int a2)
{
    if (a1==a2)return;
    atp.push_back(tp);
    aa1.push_back(a1+1);
    aa2.push_back(a2+1);
    if (tp==1)swap(cStr[a1],cStr[a2]);
        else swap(cStl[a1],cStl[a2]);
    for (int i=0; i<n-1; i++)
        if (tp==1)
        {
            if (x[i]==a1)x[i]=a2;
                else
            if (x[i]==a2)x[i]=a1;
        }else
        {
            if (y[i]==a1)y[i]=a2;
                else
            if (y[i]==a2)y[i]=a1;
        }
    if (tp==2)swap(pst[a1],pst[a2]);
}

int main()
{
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
        cStr[x[i]]++;
        cStl[y[i]]++;
    }
    for (int i=0; i<n; i++)
    {
       int mn = i;
       for (int j=i+1; j<n; j++)
          if (cStr[j]<cStr[mn])mn=j;
       mSwap(1,i,mn);
    }
    for (int i=0; i<n; i++)pst[i]=n;
    for (int i=0; i<n-1; i++)
        pst[y[i]]=min(pst[y[i]],x[i]);

    for (int i=0; i<n; i++)
    {
        int mx = i;
        for (int j=i+1; j<n; j++)
            if (cStl[j]>cStl[mx] || (cStl[j]==cStl[mx] && pst[j]<pst[mx]))mx=j;
        mSwap(2,i,mx);
    }
    cout << atp.size() << endl;
    for (int i=0; i<atp.size(); i++)
        cout << atp[i] << " " << aa1[i] << " " << aa2[i] << endl;
    return 0;
}