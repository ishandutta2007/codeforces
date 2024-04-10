#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,b,a;

bool tria()
{
        if(a>0)
        {
                a--;
                return 1;
        }
        return 0;
}

bool trib()
{
        if(b>0)
        {
                b--;
                return 1;
        }
        return 0;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>b>>a;
        int sol=0;
        int init=a;
        for(int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
              ///  cout<<b<<" "<<a<<"\n";
                if(x==0)
                {
                        if(tria())
                        {
                                sol++;
                                continue;
                        }
                        if(trib())
                        {
                                sol++;
                                continue;
                        }
                }
                else
                {
                        if(a==init && tria())
                        {
                                sol++;
                                continue;
                        }
                        if(trib())
                        {
                                a++;
                                a=min(a,init);
                                sol++;
                                continue;
                        }
                        if(tria())
                        {
                                sol++;
                                continue;
                        }
                }
                break;
        }
        cout<<sol<<"\n";
        return 0;
}