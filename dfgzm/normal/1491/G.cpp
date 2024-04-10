#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,p[maxn],is[maxn];
vector<int>C[maxn];int cnt;
void dfs(int now){
    is[now]=1;
    C[cnt].push_back(now);
    if(!is[p[now]])dfs(p[now]);
}
vector<pair<int,int>>V;
void DO(int x,int y){
    V.push_back(make_pair(x,y));
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&p[i]);
    for(i=1;i<=n;i++)
        if(!is[i]){
            ++cnt;
            dfs(i);
            if(C[cnt].size()==1)C[cnt].clear(),cnt--;
        }
    /*
        2 3 4 5 1
        -3 -2 4 5 1
        -4 -2 3 5 1
        -5 -2 3 4 1
        -5 -1 3 4 2
        -2 -1 3 4 5
        1 2 3 4 5

        2 1 A
        a 1 -2
        a 2 -1
        1 2 A
    */
    for(i=1;i<=cnt;i+=2){
        if(i==cnt){
            if(C[i].size()>2){
                DO(C[i][0],C[i][1]);
                for(int j=2;j<C[i].size()-1;j++)
                    DO(C[i][0],C[i][j]);
                DO(C[i][1],C[i][C[i].size()-1]);
                DO(C[i][0],C[i][C[i].size()-1]);
                DO(C[i][0],C[i][1]);
            }else{
                int chs;
                if(C[i][0]!=1)chs=1;
                else if(C[i][1]!=2)chs=2;
                else chs=3;
                DO(C[i][0],chs);
                DO(C[i][1],chs);
                DO(C[i][0],chs);
            }
        }else{
            DO(C[i][0],C[i+1][0]);
            for(int j=1;j<C[i].size();j++)
                DO(C[i][j],C[i+1][0]);
            for(int j=1;j<C[i+1].size();j++)
                DO(C[i+1][j],C[i][0]);
            DO(C[i][0],C[i+1][0]);
        }
    }
    cout<<V.size()<<endl;
    for(int i=0;i<V.size();i++)printf("%d %d\n",V[i].first,V[i].second);
}