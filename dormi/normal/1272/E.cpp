#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
int arr[MAXN];
int dist[2][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    queue<int> q[2];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dist[0][i]=INT_MAX;
        dist[1][i]=INT_MAX;
        if(arr[i]%2)q[0].push(i),dist[0][i]=0;
        else q[1].push(i),dist[1][i]=0;
        if(i+arr[i]<=n)matrix[i+arr[i]].push_back(i);
        if(i-arr[i]>0)matrix[i-arr[i]].push_back(i);
    }
    for(int i=0;i<2;i++){
        while(sz(q[i])){
            int cur=q[i].front();
            q[i].pop();
            for(int x:matrix[cur]){
                if(dist[i][x]>dist[i][cur]+1){
                    dist[i][x]=dist[i][cur]+1;
                    q[i].push(x);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[arr[i]%2][i]==INT_MAX){
            printf("-1 ");
        }
        else printf("%d ",dist[arr[i]%2][i]);
    }
    return 0;
}