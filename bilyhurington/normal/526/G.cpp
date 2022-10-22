/*
 * @Author: BilyHurington
 * @Date: 2020-08-13 22:24:53
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-14 15:21:08
 */
#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<int,int> > T[100010];
pair<int,int> find_node(int x,int fa,int dis){
    pair<int,int> Ans=make_pair(dis,x);
    for(int i=0;i<T[x].size();i++){
        if(T[x][i].first==fa) continue;
        Ans=max(Ans,find_node(T[x][i].first,x,dis+T[x][i].second));
    }
    return Ans;
}
struct Solve{
    int rt,max_dis[100010],son[100010],top[100010],F[100010][20],G[100010][20];
    int val[100010],bel[100010],sum[100010];vector<int> vec;
    void dfs1(int x,int fa){
        for(int i=0;i<T[x].size();i++){
            if(T[x][i].first==fa) continue;
            F[T[x][i].first][0]=x;
            G[T[x][i].first][0]=T[x][i].second;
            dfs1(T[x][i].first,x);
            if(max_dis[x]<max_dis[T[x][i].first]+T[x][i].second){
                max_dis[x]=max_dis[T[x][i].first]+T[x][i].second;
                son[x]=T[x][i].first;
            }
        }
        // printf("NODE %d: %d %d\n",x,son[x],max_dis[x]);
        for(int i=0;i<T[x].size();i++){
            if(T[x][i].first==fa||T[x][i].first==son[x]) continue;
            val[T[x][i].first]=max_dis[T[x][i].first]+T[x][i].second;
            vec.push_back(T[x][i].first);
        }
    }
    void Init(int R){
        // printf("%d\n",R);
        rt=R;
        dfs1(rt,0);
        for(int i=1;i<20;i++){
            for(int j=1;j<=n;j++){
                F[j][i]=F[F[j][i-1]][i-1];
                G[j][i]=G[j][i-1]+G[F[j][i-1]][i-1];
            }
        }
        vec.push_back(rt);val[rt]=max_dis[rt];
        sort(vec.begin(),vec.end(),[&](int x,int y){return val[x]>val[y];});
        // for(int i=0;i<vec.size();i++) printf("%d %d\n",vec[i],val[vec[i]]);
        for(int i=0;i<vec.size();i++){
            sum[i+1]=sum[i]+val[vec[i]];
            int x=vec[i];
            while(x){
                top[x]=vec[i];
                bel[x]=i+1;
                x=son[x];
            }
        }
    }
    int calc1(int x,int y){
        if(bel[x]<=y) return sum[min(y,(int)vec.size())];
        int ans=max_dis[x];
        for(int i=19;i>=0;i--){
            if(bel[F[x][i]]>=y){
                ans+=G[x][i];
                x=F[x][i];
            }
        }
        return sum[y-1]+ans+G[x][0];
    }
    int calc2(int x,int y){
        if(bel[x]<=y) return sum[min(y,(int)vec.size())];
        int ans=max_dis[x];
        for(int i=19;i>=0;i--){
            if(bel[F[x][i]]>y){
                ans+=G[x][i];
                x=F[x][i];
            }
        }
        return sum[y]-max_dis[F[x][0]]+ans+G[x][0];
    }
    int Query(int x,int y){return max(calc1(x,2*y-1),calc2(x,2*y-1));}
}S[2];
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1,x,y,z;i<n;i++){
        scanf("%d %d %d",&x,&y,&z);
        T[x].push_back(make_pair(y,z));
        T[y].push_back(make_pair(x,z));
    }
    int rot,x,y,lastans=0;
    S[0].Init(rot=find_node(1,0,0).second);
    S[1].Init(find_node(rot,0,0).second);
    while(q--){
        scanf("%d %d",&x,&y);
        x=(x+lastans-1)%n+1;
        y=(y+lastans-1)%n+1;
        lastans=max(S[0].Query(x,y),S[1].Query(x,y));
        printf("%d\n",lastans);
    }
    return 0;
}