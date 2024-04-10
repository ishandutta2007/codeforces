#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n;
pair<int,int> a[210000];
map<int,int> dic;
vector<int> ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){ scanf("%d",&a[i].first); a[i].second=i; }
    sort(a+1,a+n+1);

    //1
    dic.clear();
    for(int i=3;i<=n;i++)dic[a[i].first-a[i-1].first]++;
    if (n==2||dic[a[n].first-a[n-1].first]==n-2)ans.pb(a[1].second);

    //n
    dic.clear();
    for(int i=2;i<n;i++)dic[a[i].first-a[i-1].first]++;
    if (n==2||dic[a[2].first-a[1].first]==n-2)ans.pb(a[n].second);
    
    dic.clear();
    for(int i=2;i<=n;i++)dic[a[i].first-a[i-1].first]++;
    for(int i=2;i<n;i++)
    {
        int d=a[i+1].first-a[i-1].first;
        dic[a[i].first-a[i-1].first]--;
        dic[a[i+1].first-a[i].first]--;
        if (n<=3||dic[d]==n-3)ans.pb(a[i].second);
        dic[a[i].first-a[i-1].first]++;
        dic[a[i+1].first-a[i].first]++;
    }
    if (ans.size()==0)puts("-1"); else cout<<ans[0]<<endl;
}