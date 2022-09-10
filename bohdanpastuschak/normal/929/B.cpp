#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) x.begin(),x.end()
#define f first
#define s second

using namespace std;

int n,m;
vector<pair<int,pair<int,int> > > places;
char a[200][200];
int dy[4]={1,-1};

bool is(char c)
{
          if(c=='S' || c=='P' || c=='x')
                    return 1;
          return 0;
}

int main()
{
          cin>>n>>m;
          for(int i=1;i<=n;i++)
                    for(int j=1;j<=12;j++)
                              cin>>a[i][j];

          for(int i=1;i<=n;i++)
                    for(int j=1;j<=12;j++)
                    {
                              if(a[i][j]=='.')
                              {
                                        int kilk=0;
                                        for(int k=0;k<2;k++)
                                                  kilk+=(a[i][j+dy[k]]=='S');
                                        places.pb(mp(kilk,mp(i,j)));
                              }
                    }
          sort(all(places));
          int ans=0;
          for(int i=0;i<m;i++)
                    a[places[i].s.f][places[i].s.s]='x';

          for(int i=1;i<=n;i++)
                    for(int j=1;j<=12;j++)
                    {
                              if(a[i][j]=='S')
                              {
                                        int kilk=0;
                                        for(int k=0;k<2;k++)
                                                  if(is(a[i][j+dy[k]]))
                                                            kilk++;
                                        ans+=kilk;
                              }
                    }

          cout<<ans<<endl;
          for(int i=1;i<=n;i++)
          {
                    for(int j=1;j<=12;j++)
                              cout<<a[i][j];
                    cout<<endl;
          }

}