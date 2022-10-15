#include <bits/stdc++.h>

using namespace std;

const int N=100000;
const int G=100;
int n,m,k,s;

vector<int>good[G+5];
vector<int>v[N+5];
queue<int>q;

struct info{
    int score[G+5];
};
info sol[N+5];

void add(int ind){
    for(auto nod:good[ind]){
        q.push(nod);
        sol[nod].score[ind]=1;
    }
    while(!q.empty()){
        int nod=q.front();
        q.pop();
        for(auto nou:v[nod]){
            if(sol[nou].score[ind]==0){
                sol[nou].score[ind]=sol[nod].score[ind]+1;
                q.push(nou);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        good[a].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=k;i++){
        add(i);
    }
    for(int nod=1;nod<=n;nod++){
        sort(sol[nod].score+1,sol[nod].score+k+1);
        int solution=0;
        for(int i=1;i<=s;i++){
            solution+=sol[nod].score[i]-1;
        }
        cout<<solution<<" ";
    }
    return 0;
}
/**
**/