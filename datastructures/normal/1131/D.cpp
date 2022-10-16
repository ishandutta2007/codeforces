#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int nn,mm,n,m,f[2005];
int u[1000005],v[1000005],first[2005],nxt[1000005],du[2005],ans[2005];
int flag=1;
vector <int>c[2005];
char s[2005][2005];
inline int find(int x){
    if (x==f[x])return x;
    return f[x]=find(f[x]);
}
inline void add(int uu,int vv){
    int i=++m;
    u[i]=uu,v[i]=vv;
    nxt[i]=first[u[i]],first[u[i]]=i;
    du[v[i]]++;
    return;
}
int head,tail,cnt,q[1000005],book[2005];
inline void bfs(){
    head=1,tail=0;
    for (int i=1;i<=n;i++) 
        if (du[i]==0)book[i]=1,q[++tail]=i;
    while(head<=tail){
        ++cnt;
        int l=head,r=tail;
        head=tail+1;
        for (int i=l;i<=r;i++){
            int len=c[q[i]].size();
            for (int j=0;j<len;j++)
                ans[c[q[i]][j]]=cnt;
        }        
        for (int i=l;i<=r;i++){
            for (int j=first[q[i]];j;j=nxt[j]){
                if (book[v[j]]==1)continue;
                du[v[j]]--;
                if (du[v[j]]==0){
                    book[v[j]]=1;
                    q[++tail]=v[j];
                }
            }
        }
    }
    return;
}
int main(){
    cin>>nn>>mm;
    n=nn+mm;
    for (int i=1;i<=nn;i++)
        scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++)f[i]=i;
    for (int i=1;i<=nn;i++)
        for (int j=1;j<=mm;j++)
            if (s[i][j]=='='){
                int x=find(i),y=find(nn+j);
                if (x==y)continue;
                f[x]=y;
            }
    for (int i=1;i<=n;i++)
        c[find(i)].push_back(i);
     for (int i=1;i<=nn;i++)
        for (int j=1;j<=mm;j++){
            if (s[i][j]=='<'){
                if (find(i)==find(nn+j)){
                    flag=0;
                    continue;
                }
                add(find(i),find(nn+j));
            }
            if (s[i][j]=='>'){
                if (find(i)==find(nn+j)){
                    flag=0;
                    continue;
                }
                add(find(nn+j),find(i));
            }
        }
    bfs();
    for (int i=1;i<=n;i++)
        if (ans[i]==0)flag=0;
    if (flag==0)cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        for (int i=1;i<=nn;i++)printf("%d ",ans[i]);
        cout<<endl;
        for (int i=1;i<=mm;i++)printf("%d ",ans[nn+i]);
        cout<<endl;
    }
}