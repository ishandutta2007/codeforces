#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int,int> pi;
vector<pi> l,r;
int ans,n,x,v,len;
int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    scanf("%d%d",&x,&v);
    if (x>0) r.push_back(pi(x,v));
    else l.push_back(pi(-x,v));
  }
  sort(l.begin(),l.end());
  sort(r.begin(),r.end());
  len=min(l.size(),r.size());
  ans=0;
  for(int i=0;i<len;i++)ans+=r[i].second+l[i].second;
  if (len<l.size())ans+=l[len].second;
  if (len<r.size())ans+=r[len].second;
  printf("%d\n",ans);
  return 0;
}