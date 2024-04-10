#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=707;
const int mdn=1000000007;

char s[maxn];
int n;
vector<int> ch[maxn];
struct stt{
    int w[3][3];
    stt operator*(const stt&a)const{
        stt c;
        for(int i=0;i<3;i++){
            for(int k=0;k<3;k++){
                c.w[i][k]=0;
                for(int j=0;j<3;j++)
                    for(int j1=0;j1<3;j1++)
                        if(!(j&&(j==j1)))c.w[i][k]=(c.w[i][k]+w[i][j]*(long long)a.w[j1][k])%mdn;
            }
        }
        return c;
    }
};
stt dp[maxn];
stt sx;
void dfs(int u){
    dp[u]=sx;
    for(int i=0;i<ch[u].size();i++){
        int v=ch[u][i];
        dfs(v);
        dp[u]=dp[u]*dp[v];
    }
    dp[u]=dp[u]*sx;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(!(!!i^!!j))dp[u].w[i][j]=0;
}
int main(){
    sx.w[0][0]=sx.w[1][1]=sx.w[2][2]=1;
    cin>>(s+1);n=strlen(s+1);
    stack<int> st;st.push(0);
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            ch[st.top()].push_back(i);
            st.push(i);
        }else{
            st.pop();
        }
    }
    stt w;
    for(int i=0;i<ch[0].size();i++){
        dfs(ch[0][i]);
        if(i==0)w=dp[ch[0][i]];
        else w=w*dp[ch[0][i]];
    }
    int ans=0;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)ans=(ans+w.w[i][j])%mdn;
    cout<<ans;
    return 0;
}