#include<bits/stdc++.h>
using namespace std;
int cnt[200];
char a[30],b[30];
char ans[30];
bool succ=false;
int la,lb;
void dfs(int index,bool same){
    if (index==la){
        cout<<ans<<endl;
        succ = true;
        return;
    }
    int top = b[index];
    if (!same) top = '9';
    for (int i=top;i>='0';i--){
        if (succ){
            return;
        }
        if (cnt[i]){
            cnt[i]--;
            ans[index] =i;
            dfs(index+1,same&&i==b[index]);
            cnt[i]++;
        }
    }
}
void dfs2(int index){
    if (index==la){
        cout<<ans<<endl;
        return ;
    }
    for (int i='9';i>='0';i--){
        if (cnt[i]){
            cnt[i]--;
            ans[index] =i;
            dfs2(index+1);
        }
    }
}
int main(){
    cin>>a>>b;
    la = strlen(a);
    lb = strlen(b);
    for (int i=0;i<la;i++){
        cnt[a[i]]++;
    }
    if (lb>la){
        dfs2(0);
        return 0;
    }
    dfs(0,1);
    return 0;
}