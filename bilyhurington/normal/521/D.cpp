/*
 * @Author: BilyHurington
 * @Date: 2020-08-17 13:24:20
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-17 20:04:48
 */
#include<bits/stdc++.h>
using namespace std;
int k,n,m,opt[1000010];
long long a[100010];
long long maxn[100010];
int id[100010];
vector<pair<int,int> > v[100010];
vector<pair<double,int> > Ans;
bool cmp(pair<double,int> x,pair<double,int> y){return opt[x.second]<opt[y.second];}
int main(){
    scanf("%d %d %d",&k,&n,&m);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d %d %d",&opt[i],&x,&y);
        if(opt[i]==1){
            if(maxn[x]<y) maxn[x]=y,id[x]=i;
        }
        if(opt[i]==2){
            v[x].push_back(make_pair(y,i));
        }
        if(opt[i]==3) Ans.push_back(make_pair(y,i));
    }
    for(int i=1;i<=k;i++){
        if(id[i]&&maxn[i]>a[i]) v[i].push_back(make_pair(maxn[i]-a[i],id[i]));
        sort(v[i].begin(),v[i].end(),greater<pair<int,int> >());
        for(int j=0;j<v[i].size();j++){
            Ans.push_back(make_pair(1.0*(a[i]+v[i][j].first)/a[i],v[i][j].second));
            a[i]+=v[i][j].first;
        }
    }
    m=min(m,(int)Ans.size());
    sort(Ans.begin(),Ans.end(),greater<pair<double,int> >());
    printf("%d\n",m);
    Ans.erase(Ans.begin()+m,Ans.end());
    sort(Ans.begin(),Ans.end(),cmp);
    for(int i=0;i<m;i++) printf("%d ",Ans[i].second);
    return 0;
}//