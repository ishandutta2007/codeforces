#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef pair<int,int> pii;
#define mk make_pair
pii a[4];
vector<pii> ans;

void path(pii from,pii to)
{
    for(int i=from.first+1;i<=to.first;i++) ans.push_back(mk(i,from.second));
    if(from.second>to.second) 
        for(int i=from.second-1;i>=to.second;i--) ans.push_back(mk(to.first,i));
    else 
        for(int i=from.second+1;i<=to.second;i++) ans.push_back(mk(to.first,i));
}

int main()
{
    for(int i=1;i<=3;i++) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+4);
    if(a[1].second>a[2].second)
    {
        for(int i=a[1].first+1;i<=a[2].first;i++) ans.push_back(mk(i,a[1].second));
        for(int i=a[1].second-1;i>=a[2].second;i--) ans.push_back(mk(a[2].first,i));
    }
    else
    {
        for(int i=a[1].first+1;i<=a[2].first;i++) ans.push_back(mk(i,a[1].second));
        for(int i=a[1].second+1;i<=a[2].second;i++) ans.push_back(mk(a[2].first,i));
    }

    if(a[3].second>=min(a[1].second,a[2].second)&&a[3].second<=max(a[1].second,a[2].second))
        path(mk(a[2].first,a[3].second),a[3]);
    else if(a[3].second>max(a[1].second,a[2].second))
        path(mk(a[2].first,max(a[2].second,a[1].second)),a[3]);
    else path(mk(a[2].first,min(a[2].second,a[1].second)),a[3]);
    ans.push_back(a[1]);
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}