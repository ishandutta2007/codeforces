#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//#define F first
//#define S second
vector<int> ans[(int)5e5+2];
int main()
{
    fast_io;
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    set<int> S,X,Y;
    int k=-1;
    for(int i=0; i<n; i++) Y.insert(i);
    while(!Y.empty() || !X.empty()){
        if(X.empty()){
            k++;
            X.insert(*Y.begin());
            Y.erase(*Y.begin());
        }
        int p=*X.begin();
        ans[k].push_back(p+1);
        set<int> YP;
        for(int i=0; i<adj[p].size(); i++){
            if(Y.find(adj[p][i])!=Y.end()){
                YP.insert(adj[p][i]);
                Y.erase(adj[p][i]);
            }
        }
        for(set<int>::iterator it=Y.begin();it!=Y.end();it++){
            X.insert(*it);
        }
        Y=YP;
        X.erase(p);
    }
    cout << k+1 << '\n';
    for(int i=0; i<=k; i++){
        cout << ans[i].size() << ' ';
        for(int j=0; j<ans[i].size(); j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
	return 0;
}