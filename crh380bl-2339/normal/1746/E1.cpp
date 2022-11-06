#include<bits/stdc++.h>
#define N 100005
#define MAXM 300
using namespace std;
map<int, int>M[N], to[N];
set<int>vis[N];
vector<pair<int,int>>v;
int b[1002][1002];
int DFS(int n,int a){
    //printf("%d %d\n",n,a);
    if(n<=2){
        M[n][a]=0;
        return 0;
    }
    if(vis[n].find(a)!=vis[n].end())return M[n][a];
    vis[n].insert(a);
    ++b[n][a];
    assert(b[n][a]<=1);
    int i,val,ans=1e9;
    if(a==0){
        val=n/2;
        for(i=val;i<=val;++i){
            int tmp=1+max(DFS(n,i), DFS(n,n-i));
            if(tmp<ans){
                ans=tmp;
                to[n][a]=i;
            }
        }
        return M[n][a]=ans;
    }
    else{
        for(i=1;i<=max(n-a-1,1);++i){
            int tmp=1+max(DFS(n-i,0),DFS(a+i, i));
            if(tmp<ans){
                ans=tmp;
                to[n][a]=i;
            }
        }
        return M[n][a]=ans;
    }
}
void answer(const int x){
    printf("! %d\n",x);
    fflush(stdout);
}
int step=0;
void solve(int a){
    // printf("--STEP:%d--\n",++step);
    // for(auto p:v){
    //     if(p.first==0)printf("(%d)",p.second);
    //     else printf("[%d]",p.second);
    // }
    // puts("");
    string s;
    if(v.size()==1){
        answer(v[0].second);
        cin>>s;
        return;
    }
    if(v.size()==2){
        answer(v[0].second);
        cin>>s;
        if(s==":("){
            answer(v[1].second);
            cin>>s;
        }
        return;
    }
    if(a==0){
        int m=v.size()/2,i;
        printf("? %d",m);
        for(i=0;i<m;++i){
            printf(" %d",v[i].second);
        }
        puts("");fflush(stdout);
        cin>>s;
        if(s=="NO"){
            for(i=m;i<v.size();++i)v[i].first=1;
            solve(v.size()-m);
        }
        else{
            for(i=0;i<m;++i)v[i].first=1;
            sort(v.begin(),v.end());
            solve(m);        
        }
        return;
    }
    int m,i;
    if(v.size()<=MAXM){
        DFS(v.size(), a);
        m=to[v.size()][a];
    }
    else m=max(1ULL,min((v.size()+2)/3, v.size()-a));
    //printf("%d %d:%d\n",v.size(),a,m);
    printf("? %d",m);
    for(i=0;i<m;++i){
        printf(" %d",v[i].second);
    }
    puts("");
    fflush(stdout);
    cin>>s;
    vector<pair<int,int>>v1;
    if(s=="NO"){
        for(i=m;i<v.size();++i){
            v[i].first=0;
            v1.push_back(v[i]);
        }
        v=v1;
        solve(0);
        return;
    }
    else{
        for(i=0;i<m;++i){
            v1.push_back(v[i]);
            v1[i].first=1;
        }
        for(i=m;i<v.size();++i){
            if(v[i].first){
                v[i].first=0;
                v1.push_back(v[i]);
            }
        }
        v=v1;
        sort(v.begin(),v.end());
        solve(m);
        return;
    }

}
int main(){
    int n;
    //printf("%d\n",DFS(100,0));
    scanf("%d",&n);
    for(int i=1;i<=n;++i)v.emplace_back(0,i);
    string s;
    if(v.size()==1){
        answer(v[0].second);
        cin>>s;
        return 0;
    }
    if(v.size()==2){
        answer(v[0].second);
        cin>>s;
        if(s==":("){
            answer(v[1].second);
            cin>>s;
        }
        return 0;
    }
    int m=n/2,i;
    printf("? %d",m);
    for(i=0;i<m;++i){
        printf(" %d",i+1);
    }
    puts("");fflush(stdout);
    cin>>s;
    if(s=="NO"){
        for(i=m;i<v.size();++i)v[i].first=1;
        solve(n-m);
    }
    else{
        for(i=0;i<m;++i)v[i].first=1;
        sort(v.begin(),v.end());
        solve(m);        
    }
    return 0;
}

/*
6
? 3 1 2 3
YES
? 2 4 5
YES
? 3 1 2 3
YES
? 1 4
NO
? 2 5 1
NO
? 2 5 1
NO
! 2
:(
! 3
:(
*/