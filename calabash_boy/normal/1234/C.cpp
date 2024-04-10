#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const char* YES = "YES";
const char* NO = "NO";
char mp[2][maxn];
bool vis[2][maxn];
int get_type(char ch){
    return ch == '1' || ch == '2'?1:2;
}
int main(){
    int Q;
    cin>>Q;
    while (Q--){
        int n;
        cin>>n;
        cin>> &mp[0][1];
        cin>> &mp[1][1];
        mp[0][0] = 1;
        mp[1][0] = 1;
        vis[0][0] = 1;
        vis[1][0] = 0;
        for (int i=1;i<=n;i++){
            vis[0][i] = vis[1][i] = 0;
            if (vis[0][i-1] || vis[1][i-1]){
                int type0 = get_type(mp[0][i]);
                int type1 = get_type(mp[1][i]);
                if (type0 == 1)vis[0][i] = vis[0][i-1];
                if (type1 == 1)vis[1][i] = vis[1][i-1];
                if (type0 == 2 && type1 == 2){
                    vis[0][i] = vis[1][i-1];
                    vis[1][i] = vis[0][i-1];
                }
            }
        }
        cout<< (vis[1][n]? YES: NO)<<endl;
    }
    
    return 0;
}