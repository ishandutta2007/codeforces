#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int N=200000;
int n,v[N+5],sol=0;

map<int,int>best;

int lst=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        int x=v[i];
        best[x]=1+best[x-1];
        if(best[x]>sol)
        {
            sol=best[x];
            lst=x;
        }
    }
    cout<<sol<<"\n";
    int st=lst-sol+1;
    for(int i=1;i<=n;i++)
        if(v[i]==st)
        {
            cout<<i<<" ";
            st++;
            if(st>lst)
                break;
        }
    return 0;
}
/**
**/