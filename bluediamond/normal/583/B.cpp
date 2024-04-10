#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

const int N=1000+5;

int n;
int v[N];
int kek=0;
int lft;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    lft=n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    int p=1,res=0;
    res--;
    while(lft)
    {
        res++;
        if(p==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(v[j]!=-1 && kek>=v[j])
                {
                    kek++;
                    v[j]=-1;
                    lft--;
                }
            }
        }
        else
        {
            for(int j=p;j>=1;j--)
            {
                if(v[j]!=-1 && kek>=v[j])
                {
                    kek++;
                    v[j]=-1;
                    lft--;
                }
            }
        }
        p=n+1-p;
    }
    cout<<res<<"\n";
    return 0;
}
/**


**/