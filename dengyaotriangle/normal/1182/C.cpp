#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxl=1000005;

string x[maxn];
int n;
int wc[maxn],wi[maxn];
vector<int> h[maxl];
pair<int,int> p1[maxn];
pair<int,int> p2[maxn];
int c1,c2;
pair<int,int> ans1[maxn];
pair<int,int> ans2[maxn];
vector<int> e[7];


int wcl(char q){
    if(q=='a') return 1;
    if(q=='e') return 2;
    if(q=='o') return 3;
    if(q=='i') return 4;
    if(q=='u') return 5;
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        int s=x[i].size();
        for(int j=s-1;j>=0;j--){
            if(wcl(x[i][j])!=-1){
                if(!wi[i]){
                    wi[i]=wcl(x[i][j]);
                }
                wc[i]++;
            }
        }
        h[wc[i]].push_back(i);
    }
    for(int i=1;i<maxl-1;i++){
        if(0==h[i].size())continue;
        for(int j=0;j<6;j++)e[j].clear();
        for(int j=0;j<h[i].size();j++){
            int u=h[i][j];
            e[wi[u]].push_back(u);
        }
        int cur=0;
        for(int j=1;j<=5;j++){
            int s=0;
            if(e[j].size()%2==0){
                s=0;
            }else{
                s=1;
                if(cur){
                    p2[++c2]=make_pair(cur,e[j][0]);
                    cur=0;
                }else cur=e[j][0];
            }
            for(int k=s;k<e[j].size();k+=2){
                p1[++c1]=make_pair(e[j][k],e[j][k+1]);
            }
        }
    }
    int cnt=0;
    int i2=0,i1=c1;
    for(int i=1;i<=i1;i++){
        ans1[++cnt]=p1[i];
        if(i2==c2){
            if(i==i1){
                cnt--;
                break;
            }
            ans2[cnt]=p1[i1--];
        }else ans2[cnt]=p2[++i2];
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=cnt;i++){
        cout<<x[ans2[i].first]<<' '<<x[ans1[i].first]<<'\n';
        cout<<x[ans2[i].second]<<' '<<x[ans1[i].second]<<'\n';
    }
    return 0;
}