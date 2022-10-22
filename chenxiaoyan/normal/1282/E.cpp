#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int N=100000;
int n;
int a[N+1],b[N+1],c[N+1];
vector<int> hav[N+1];
bool del[N+1];
int cnt[N+1];
vector<pair<int,pair<int,int> > > v;
list<int>::iterator it[N+1];
list<int>::iterator operator+(list<int>::iterator x,int){return ++x;}
void mian(){
    cin>>n;
    //clear
    for(int i=1;i<=n;i++)hav[i].clear();
    memset(del,0,sizeof(del)),memset(cnt,0,sizeof(cnt));
    v.clear();
    for(int i=1;i<=n-2;i++)
        scanf("%d%d%d",a+i,b+i,c+i),
        cnt[a[i]]++,cnt[b[i]]++,cnt[c[i]]++,
        hav[a[i]].pb(i),hav[b[i]].pb(i),hav[c[i]].pb(i);
    queue<int> q;
    for(int i=1;i<=n;i++)if(cnt[i]==1)q.push(i);
    vector<int> ans2;
    for(int i=1;i<n-2;i++){
        int x=q.front();
        q.pop();
        for(int i=0;i<hav[x].size();i++)if(!del[hav[x][i]]){
            int fd=hav[x][i];
            ans2.pb(fd);
            if(b[fd]==x)swap(a[fd],b[fd]);
            else if(c[fd]==x)swap(a[fd],c[fd]);
            v.pb(mp(x,mp(b[fd],c[fd])));
            del[fd]=true;
            if(--cnt[b[fd]]==1)q.push(b[fd]);
            if(--cnt[c[fd]]==1)q.push(c[fd]);
            break;
        }
    }
    list<int> lis;
    for(int i=1;i<=n-2;i++)if(!del[i]){
        ans2.pb(i);
        lis.pb(a[i]),it[a[i]]=--lis.end();
        lis.pb(b[i]),it[b[i]]=--lis.end();
        lis.pb(c[i]),it[c[i]]=--lis.end();
    }
    for(int i=n-4;~i;i--){
        int x=v[i].X,l=v[i].Y.X,r=v[i].Y.Y;
        if(it[l]+1==it[r]||it[l]==--lis.end()&&it[r]==lis.begin())
            lis.insert(it[l]+1,x),it[x]=it[l]+1;
        else lis.insert(it[r]+1,x),it[x]=it[r]+1;
    }
    for(list<int>::iterator i=lis.begin();i!=lis.end();i++)printf("%d ",*i);puts("");
    for(int i=0;i<ans2.size();i++)printf("%d ",ans2[i]);puts("");
}
int main(){
    int testnum;
    cin>>testnum;
    while(testnum--)mian();
    return 0;
}