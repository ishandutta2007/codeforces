#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX_N=102;
bool m1[MAX_N];
int n,m;
vector<int> adj[MAX_N];
bool a[MAX_N][MAX_N];
void dfs(int v){
    m1[v]=true;
    for(int i : adj[v]){
        if(!m1[i]) dfs(i);
    }
}
int main(){
    int maxk=-1;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        if(maxk<k) maxk=k;
        for(int j=0; j<k; j++){
            int t;
            cin >> t;
            a[i][t-1]=true;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(a[i][k]==1 && a[j][k]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    int cnt=-1;
    for(int i=0; i<n; i++){
        if(!m1[i]){
            cnt++;
            dfs(i);
        }
    }
    if(maxk==0){
        cout << n;
        return 0;
    }
    cout << cnt;
    return 0;
}