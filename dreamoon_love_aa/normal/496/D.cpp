#include<cstdio>
#include<algorithm>
using namespace std;
const int SIZE = 2e5;
int ann;
int n,a[SIZE];
int pos[3][SIZE],from[SIZE],nn[3],nxt[SIZE][3];
pair<int,int>pp[SIZE];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        pos[a[i]][nn[a[i]]]=i;
        from[i]=nn[a[i]];
        nn[a[i]]++;
    }
    nxt[n][1]=nxt[n][2]=n;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=2;j++)nxt[i][j]=nxt[i+1][j];
        nxt[i][a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int now=0;
        int cnt[3]={};
        bool err=0;
        int lt=0;
        while(now<n){
            int ha[3]={n,n,n};
            for(int k=1;k<=2;k++){
                if(nxt[now][k]!=n&&from[nxt[now][k]]+i<=nn[k]){
                    ha[k]=pos[k][from[nxt[now][k]]+i-1];
                }
            }
            if(ha[1]==n&&ha[2]==n){
                err=1;
                break;
            }
            if(ha[1]<ha[2])cnt[1]++,lt=1;
            else cnt[2]++,lt=2;
            now=min(ha[1],ha[2])+1;
        }
        if(err)continue;
        if((cnt[1]<cnt[2]&&lt==2)||(cnt[1]>cnt[2]&&lt==1)){
            pp[ann++]=make_pair(max(cnt[1],cnt[2]),i);
        }
    }
    sort(pp,pp+ann);
    printf("%d\n",ann);
    for(int i=0;i<ann;i++){
        printf("%d %d\n",pp[i].first,pp[i].second);
    }
    return 0;
}