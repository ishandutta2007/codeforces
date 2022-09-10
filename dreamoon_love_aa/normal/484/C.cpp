#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE = 1e6+5;
char s[SIZE],nxt[SIZE];
int n;
vector<int>qq[SIZE];
int from[SIZE],used[SIZE],tt,No;
pair<int,int>be[SIZE];
void go(int k,int d){
    int tmp=0;
    for(int i=0;i<d;i++){
        for(int j=i;j<k;j+=d)from[tmp++]=j+1;
    }
    from[k]=0;
    tt++;
    No=0;
    for(int i=0;i<=k;i++){
        if(used[i]==tt)continue;
        qq[No].clear();
        int now=i;
        while(used[now]!=tt){
            be[now]=make_pair(No,qq[No].size());
            used[now]=tt;
            qq[No].push_back(now);
            now=from[now];
        }
        No++;
    }
    //for(int i=0;i<=k;i++)printf("from[%d]=%d\n",i,from[i]);
    int all=n-k+1;
    for(int i=0;i<n;i++){
        if(i<k){
            if(be[i+1].first==0){
                if(be[i+1].second>=all)nxt[n-k+qq[0][be[i+1].second-all]]=s[i];
                else nxt[be[i+1].second-1]=s[i];
            }
            else{
                int me=be[i+1].first;
                //if(i==1)printf("[%d]\n",n-k+qq[me][((be[i+1].second-all)%(int)qq[me].size()+(int)qq[me].size())%(int)qq[me].size()]-1);
                nxt[n-k+qq[me][((be[i+1].second-all)%(int)qq[me].size()+(int)qq[me].size())%(int)qq[me].size()]]=s[i];
            }
        }
        else{
            all=n-i;
            if(be[k].first==0){
                if(be[k].second>=all)nxt[n-k+qq[0][be[k].second-all]]=s[i];
                else nxt[i-k+1+be[k].second-1]=s[i];
            }
            else{
                int me=be[k].first;
                nxt[n-k+qq[me][((be[k].second-all)%(int)qq[me].size()+(int)qq[me].size())%(int)qq[me].size()]]=s[i];
            }
            
        }
    }
    puts(nxt);
    strcpy(s,nxt);
}
int main(){
    scanf("%s",s);
    n=strlen(s);
    int m;
    scanf("%d",&m);
    while(m--){
        int k,d;
        scanf("%d%d",&k,&d);
        go(k,d);
    }
    return 0;
}