/*
 * @Author: BilyHurington
 * @Date: 2020-08-08 22:18:55
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-09 10:42:55
 */
#include<bits/stdc++.h>
using namespace std;
int n,sz[1010],tag[1010];
bitset<1010> bs[1010],B,ed[1010];
vector<pair<int,int> > Ans;
int main(){
    scanf("%d",&n);
    if(n==2){printf("1 2");return 0;}
    bool pd=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&sz[i]);
        if(sz[i]<n) pd=0;
        for(int j=1,x;j<=sz[i];j++) scanf("%d",&x),bs[i][x]=1;
    }
    if(pd){for(int i=2;i<=n;i++) printf("1 %d\n",i);return 0;}
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            B=bs[i]&bs[j];
            // for(int i=1;i<=n;i++) printf("%d",(int)B[i]);printf("\n");
            if(B.count()!=2) continue;
            int x=B._Find_first(),y=B._Find_next(x);
            if(ed[x][y]) continue;
            // printf("%d %d %d %d\n",i,j,x,y);
            ed[x][y]=ed[y][x]=1;
            Ans.push_back(make_pair(x,y));
            cnt-=tag[x]+tag[y];
            tag[x]=tag[y]=1;
            cnt+=tag[x]+tag[y];
        }
    }
    for(int i=1;i<=n;i++) if(tag[i]) ed[i][i]=1;
    if(cnt==2){
        int x=Ans[0].first,y=Ans[0].second;
        printf("%d %d\n",x,y);
        for(int j=1;j<=n;j++){
            if(sz[j]<n){
                for(int k=1;k<=n;k++){
                    if(tag[k]) continue;
                    if(bs[j][k]) printf("%d %d\n",k,x);
                    else printf("%d %d\n",k,y);
                }
                break;
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(!tag[i]) B[i]=0;
        else B[i]=1;
    }
    // for(int i=1;i<=n;i++) printf("%d",(int)B[i]);printf("\n");
    for(int i=1;i<=n;i++){
        if(tag[i]) continue;
        // printf("");
        int x=0,minn=n+1;
        for(int j=1;j<=n;j++){
            if(bs[j][i]&&sz[j]<minn) minn=sz[j],x=j;
        }
        // for(int j=1;j<=n;j++) printf("%d",(int)(bs[x]&B)[j]);printf("\n");
        for(int j=1;j<=n;j++){
            if(!tag[j]) continue;
            // for(int k=1;k<=n;k++) printf("%d",(int)ed[j][k]);printf("\n");
            if(ed[j]==(bs[x]&B)) Ans.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<Ans.size();i++) printf("%d %d\n",Ans[i].first,Ans[i].second);
    return 0;
}