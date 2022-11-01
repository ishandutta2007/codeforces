#include<bits/stdc++.h>
using namespace std;

int n,m,pre[405][405];
char g[405][405];

int sum(int x1,int y1,int x2,int y2){
    return pre[x2][y2]+pre[x1-1][y1-1]-pre[x1-1][y2]-pre[x2][y1-1];
}

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>g[i]+1;
        for(int j=1;j<=m;j++){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+g[i][j]-'0';
        }
    }
    int ans=50;
    for(int top=1;top<=n;top++){
        for(int bot=top+4;bot<=n;bot++){
            int mn=50;
            vector<int> prv;
            for(int i=1;i<=m;i++){
                int c=bot-top-1-sum(top+1,i,bot-1,i);
                prv.emplace_back(c);
                if(prv.size()==4){
                    mn=min(mn,prv.front());
                    prv.erase(prv.begin());
                }
                if(i>3)ans=min(ans,mn+c);
                int add=(g[top][i]!='1')+(g[bot][i]!='1')+sum(top+1,i,bot-1,i);
                for(int i=0;i+1<prv.size();i++)prv[i]+=add;
                mn+=add;
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}