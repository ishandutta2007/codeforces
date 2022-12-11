#include<bits/stdc++.h>
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
using namespace std;
const int N=2e5+50;
int n,p1[N],p2[N],n1,n2;char a[N],b[N];
vector<pii>ans;
int main(){
    scanf("%d%s%s",&n,a+1,b+1);
    for(int i=1;i<=n;i++){
        if(a[i]=='a'&&b[i]=='b')p1[++n1]=i;
        if(a[i]=='b'&&b[i]=='a')p2[++n2]=i;
    }
    while(n1>=2)ans.pb(mp(p1[n1],p1[n1-1])),n1-=2;
    while(n2>=2)ans.pb(mp(p2[n2],p2[n2-1])),n2-=2;
    if(n1&&!n2||n2&&!n1)puts("-1"),exit(0);
    if(n1)ans.pb(mp(p1[n1],p1[n1])),ans.pb(mp(p1[n1],p2[n2]));
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}