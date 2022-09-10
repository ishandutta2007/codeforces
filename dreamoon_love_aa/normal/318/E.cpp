#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 322
int a[SIZE],b[SIZE],e[SIZE][SIZE],used[SIZE],n,v;
long long aa,bb;
vector<int>qq;
vector<int>tree[SIZE],emp;
void dfs(int x){
    aa+=a[x];
    bb+=b[x];
    used[x]=1;
    int i;
    for(i=1;i<=n;i++){
        if(used[i])continue;
        if(e[x][i]){
            tree[x].pb(i);
            tree[i].pb(x);
            dfs(i);
        }
    }
    qq.pb(x);
}
struct Answer{
    int x,y,v;
    Answer(int _x=0,int _y=0,int _v=0){x=_x;y=_y;v=_v;}
};
vector<Answer>an;
int st;
void go1(int x,int last){
    int i;
    for(i=0;i<tree[x].size();i++){
        if(used[tree[x][i]]==2)continue;
        if(tree[x][i]==last)continue;
        go1(tree[x][i],x);
    }
    if(last&&last!=st){
        int tmp=min(v-a[last],a[x]);
        if(tmp){
            an.pb(Answer(x,last,tmp));
            a[last]+=tmp;
            a[x]-=tmp;
        }
    }
    else if(last==st){
        int tmp=min(b[st]-a[last],a[x]);
        if(tmp){
            an.pb(Answer(x,last,tmp));
            a[last]+=tmp;
            a[x]-=tmp;
        }
    }
}
void go2(int x,int last){
    int i;
    for(i=0;i<tree[x].size();i++){
        if(used[tree[x][i]]==2)continue;
        if(tree[x][i]==last)continue;
        go2(tree[x][i],x);
    }
    if(last&&last!=st){
        int tmp=min(a[last],v-a[x]);
        if(tmp){
            an.pb(Answer(last,x,tmp));
            a[last]-=tmp;
            a[x]+=tmp;
        }
    }
    else if(last==st){
        int tmp=min(a[last]-b[st],v-a[x]);
        if(tmp){
            an.pb(Answer(last,x,tmp));
            a[last]-=tmp;
            a[x]+=tmp;
        }
    }
}
int main(){
    int i,j,k,mm;
    cin>>n>>v>>mm;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)cin>>b[i];
    while(mm--){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }
    for(i=1;i<=n;i++){
        if(!used[i]){
            aa=bb=0;
            qq.clear();
            for(j=1;j<=n;j++)tree[j]=emp;
            dfs(i);
            if(aa!=bb)break;
            for(j=0;j<qq.size();j++){
                st=qq[j];
                if(a[st]<b[st])
                    go1(st,0);
                else if(a[st]>b[st])
                    go2(st,0);
                used[qq[j]]=2;
            }
        }
    }
    if(i<=n)puts("NO");
    else{
        printf("%d\n",an.size());
        for(i=0;i<an.size();i++){
            printf("%d %d %d\n",an[i].x,an[i].y,an[i].v);
        }
    }
    return 0;
}