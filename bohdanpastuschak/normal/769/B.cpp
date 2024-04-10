#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp( pair<int,int> x, pair<int,int> y)
{
          return x>y;
}

int main()
{
          int n;
          cin>>n;
          pair<int,int> a[101];
          cin>>a[0].first;
          a[0].second=1;
          int s(0);
          for(int i=1;i<n;i++)
          {
                    cin>>a[i].first;
                    s+=a[i].first;
                    a[i].second=i+1;
          }
          if(s+a[0].first+1<n || a[0].first==0)
          {
                    cout<<-1;
                    return 0;
          }
          sort(a+1,a+n,&cmp);
          int f1=0;
          int f2=0;
          cout<<n-1<<endl;
          while(++f2!=n)
          {
                    if(a[f1].first==0)
                              f1++;
                    a[f1].first--;
                    cout<<a[f1].second<<" "<<a[f2].second<<endl;
          }

}