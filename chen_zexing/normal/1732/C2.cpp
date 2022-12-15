#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int p[30][100005];
vector <int> v[30];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<30;i++){
            v[i].clear();
            for(int j=1;j<=n;j++){
                p[i][j]=((1<<i)&a[j])>0;
                if(p[i][j]) v[i].push_back(j);
            }
            for(int j=1;j<=n;j++) p[i][j]+=p[i][j-1];
        }
        for(int i=1,l,r;i<=q;i++){
            scanf("%d%d",&l,&r);
            int ansl=r,ansr=l;
            vector <int> pl;
            vector <pair<int,int>> ch;
            for(int j=0;j<30;j++){
                int c=p[j][r]-p[j][l-1];
                //cout<<j<<" "<<c<<endl;
                if(c<=1) continue;
                if(c%2==0){
                    auto it=lower_bound(v[j].begin(),v[j].end(),l);
                    ansl=min(ansl,*it);
                    it=upper_bound(v[j].begin(),v[j].end(),r);
                    --it;
                    ansr=max(ansr,*it);
                }
                else{
                    auto it=lower_bound(v[j].begin(),v[j].end(),l);
                    int ll=*it;
                    ++it;
                    ansl=min(ansl,*it);
                    it=upper_bound(v[j].begin(),v[j].end(),r);
                    --it;
                    int rr=*it;
                    --it;
                    ansr=max(ansr,*it);
                    pl.push_back(ll),ch.push_back({ll,rr});
                }
            }
            if(ansl>ansr) printf("%d %d\n",l,l);
            else if(!pl.size()) printf("%d %d\n",ansl,ansr);
            else{
                int ll=l,rr=r;
                for(auto t:pl){
                    int tmpl,tmpr;
                    tmpl=min(t,ansl),tmpr=ansr;
                    for(auto c:ch) if(c.first<t) tmpr=max(tmpr,c.second);
                    if(tmpr-tmpl<rr-ll) rr=tmpr,ll=tmpl;
                }
                int tmpl=ansl,tmpr=ansr;
                for(auto c:ch) tmpr=max(tmpr,c.second);
                if(tmpr-tmpl<rr-ll) rr=tmpr,ll=tmpl;
                printf("%d %d\n",ll,rr);
            }
        }
    }
    return 0;
}