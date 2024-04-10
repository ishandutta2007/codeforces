#include <iostream>
#define ll long long
#include <map>
#include <fstream>

using namespace std;

ll  diffBits(ll a, ll  b)
{
          ll u = a^b;
          ll uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
          return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

map<ll ,ll> mp;
map<ll  ,ll > :: iterator it;
map<ll  ,ll > :: iterator itt;



int main()
{
          //freopen("input.txt", "r", stdin);
          //freopen("output.txt", "w", stdout);
          int n,k;
          scanf("%d %d",&n,&k);
          int  x;
          ll res(0);
          for(int i=0;i<n;i++)
          {
                    scanf("%d", &x);
                    mp[x]++;
          }
          if(k==0)
          {
                    for(it=mp.begin();it!=mp.end();it++)
                              res+=(it->second)*(it->second-1)/2;
          }
          else
                    for(it=mp.begin();it!=mp.end();it++)
                    {
                              for(itt=mp.begin();itt!=it;itt++)
                              {
                                        if(diffBits(itt->first,it->first)==k)
                                        {
                                                  res+=itt->second*it->second;
                                        }
                              }
                    }
          cout<<res;

}