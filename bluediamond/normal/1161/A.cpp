#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;
int n,k;
int v[N];
int fi[N];
int ls[N];
int res=0;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>k;
        for(int i=1;i<=k;i++)
        {
                cin>>v[i];
                if(fi[v[i]]==0)
                {
                        fi[v[i]]=i;
                }
                ls[v[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
                for(int j=i-1;j<=i+1;j++)
                {
                        if(1<=j && j<=n)
                        {
                                if(fi[i]==0 || fi[j]==0)
                                {
                                 //       cout<<i<<" "<<j<<"\n";
                                        res++;
                                        continue;
                                }
                                int p=fi[i];
                                if(ls[j]<p)
                                {
                                   //     cout<<i<<" "<<j<<"\n";
                                        res++;
                                }
                        }
                }
        }
        cout<<res<<"\n";
        return 0;
}
/**

**/