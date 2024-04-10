#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000;
string a;
int n,t[N+5];
int cnt0=0,cnt1=0;
bool viz[N+5];
int who0[N+5],who1[N+5];
vector<int>sl[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    n=a.size();
    for(int i=0;i<n;i++)
        if(a[i]=='0')
        {
            who0[++cnt0]=i;
            if(cnt1)
            {
                t[i]=who1[cnt1];
                cnt1--;
            }
            else
                t[i]=-1;
        }
        else
        {
            t[i]=who0[cnt0];
            cnt0--;
            if(cnt0<0)
            {
                cout<<"-1\n";
                return 0;
            }
            who1[++cnt1]=i;
        }
    if(cnt1)
    {
        cout<<"-1\n";
        return 0;
    }
    int cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        if(viz[i]==1)
            continue;
        cnt++;
        int nod=i;
        while(nod!=-1)
        {
            sl[cnt].push_back(nod);
            viz[nod]=1;
            nod=t[nod];
        }
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;i++)
    {
        cout<<sl[i].size()<<" ";
        reverse(sl[i].begin(),sl[i].end());
        for(auto itr:sl[i])
        {
            cout<<itr+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/**
**/