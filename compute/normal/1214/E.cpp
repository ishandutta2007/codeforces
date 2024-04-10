#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int dep[maxn];
int p[maxn];
typedef pair<int,int> PII;
PII a[maxn];
vector<PII> ans;
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int d;
    scanf("%d",&d);
    a[i-1]=make_pair(d,i*2-1);
  }
  sort(a,a+n,greater<PII>());
  int cur=0;
  int pre=-1;
  for(int i=0;i<n;i++)
  {
    dep[a[i].second]=cur;
    p[cur]=a[i].second;
    cur++;
    if(pre!=-1) ans.push_back(make_pair(pre,a[i].second));
    pre=a[i].second;
  }
  for(int i=0;i<n;i++)
  {
    int u=a[i].second,v=a[i].second+1;
    int d=a[i].first;
    int tar=dep[u]+d-1;
    if(!p[tar]) tar=dep[u]-d+1;
    if(!p[tar+1]) p[tar+1]=v;
    assert(p[tar]);
    ans.push_back(make_pair(p[tar],v));
  }
  for(auto u:ans) printf("%d %d\n",u.first,u.second);
}