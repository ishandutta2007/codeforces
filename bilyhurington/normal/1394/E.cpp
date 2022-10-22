/*
 * @Author: BilyHurington
 * @Date: 2020-11-30 18:32:29
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-11-30 19:52:43
 */
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> ser[100010];
vector<int> LP[100010],RP[100010];
int dfs(int L,int R){
    if(ser[R].count(L)){
        // printf("DFS: %d %d %d\n",L,R,ser[R][L]);
        return ser[R][L];
    }
    int ans=0;
    for(int i=0;i<LP[L].size()&&L+2*LP[L][i]-1<=R;i++) ans=max(ans,dfs(L+LP[L][i],R)+1);
    for(int i=0;i<RP[R].size()&&R-2*RP[R][i]+1>=L;i++) ans=max(ans,dfs(L,R-RP[R][i])+1);
    // printf("DFS: %d %d %d\n",L,R,ans);
    return ser[R][L]=ans;
}
int n,m,S[100010];
int main(){
    int ch,sumz=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&ch);
        if(ch==S[m]){RP[m+1].push_back(1);}
        for(int i=0;i<RP[m].size();i++) if(S[m-RP[m][i]*2]==ch){
            RP[m+1].push_back(RP[m][i]+1);
            // printf("RP %d %d\n",m+1,RP[m][i]+1);
        }
        int zlen=0;
        for(int i=RP[m+1].size()-1;i>=0;i--){
            int pos=m+1-RP[m+1][i];
            int x=lower_bound(RP[pos].begin(),RP[pos].end(),RP[m+1][i])-RP[pos].begin();
            if(x!=RP[pos].size()&&RP[pos][x]==RP[m+1][i]){zlen=RP[m+1][i];break;}
        }
        S[++m]=ch;
        for(int i=0;i<RP[m].size();i++){
            LP[m-2*RP[m][i]+1].push_back(RP[m][i]);
            // printf("LP %d %d\n",m-2*RP[m][i]+1,RP[m][i]);
        }
        if(zlen){
            for(int ti=0;ti<2*zlen;ti++){
                for(int i=0;i<RP[m].size();i++) LP[m-2*RP[m][i]+1].pop_back();
                RP[m].clear();ser[m].clear();m--;
            }++sumz;
        }
        printf("%d ",sumz*2+dfs(1,m));
        // printf("S: ");for(int i=1;i<=m;i++) printf("%d ",S[i]);puts("");
    }
    return 0;
}