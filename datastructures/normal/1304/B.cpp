#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,m;
char s[1005][1005];
int book[1005],ans1[1005],ans2[1005],tot;
int mxid=-1;
signed main(){
 //   freopen("b.in","r",stdin);
 //   freopen("b.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++){
        if (book[i]==1)continue; 
        int id=-1;
        for (int j=i+1;j<=n;j++){
            int flag=1;
            for (int k=1;k<=m;k++)
                if (s[i][k]!=s[j][m-k+1]||book[j]==1)flag=0;
            if (flag==1)id=j;
        }
        if (id!=-1){
            tot++;
            ans1[tot]=i,ans2[tot]=id;
            book[i]=book[id]=1;
        }
        else{
            int flag=1;
            for (int k=1;k<=m;k++){
                if (s[i][k]!=s[i][m-k+1])flag=0;
            }
            if (flag==1)mxid=i;
        }
    }
    int saa=0;
    if (mxid!=-1)saa+=m;
    saa+=2*tot*m;
    cout<<saa<<endl;
    for (int i=1;i<=tot;i++){
        for (int j=1;j<=m;j++)cout<<s[ans1[i]][j];
    }
    if (mxid!=-1){
        for (int j=1;j<=m;j++)cout<<s[mxid][j];
    }
    for (int i=tot;i>=1;i--){
        for (int j=1;j<=m;j++)cout<<s[ans2[i]][j];
    }
    cout<<endl;
    return 0;
}