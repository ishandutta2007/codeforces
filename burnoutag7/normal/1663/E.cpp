#include<bits/stdc++.h>
using namespace std;

string m="minotaur",t="theseus";
int n;
vector<string> g;
int dx[]={0,1,1},dy[]={1,1,0};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    g.resize(n);
    for(auto &s:g)cin>>s;
    bool havm=0,havt=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        for(int d=0;d<3;d++){
            bool same=true;
            for(int len=0;len<8;len++){
                int x=dx[d]*len+i,y=dy[d]*len+j;
                same&=x>=0&&y>=0&&x<n&&y<n&&g[x][y]==m[len];
            }
            havm|=same;
        }
        for(int d=0;d<3;d++){
            bool same=true;
            for(int len=0;len<7;len++){
                int x=dx[d]*len+i,y=dy[d]*len+j;
                same&=x>=0&&y>=0&&x<n&&y<n&&g[x][y]==t[len];
            }
            havt|=same;
        }
    }
    cout<<(havm||!havt?"NO":"YES");

    return 0;
}