#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
bool m1[(int)2e5+10];
int ans[(int)2e5+10],a[(int)2e5+10];
int dfs(int v, int c){
    if(m1[v]==true){
        return c;
    }
    m1[v]=true;
    ans[v]=dfs(a[v],c+1);
    return ans[v];
}
int main()
{
    int q;
    cin >> q;
    while(q--){
        fill(m1,m1+(int)2e5+10,false);
        fill(ans,ans+(int)2e5+10,0);
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
            a[i]--;
        }
        for(int i=0; i<n; i++){
            if(!m1[a[i]]) dfs(a[i],0);
        }
        for(int i=0; i<n; i++) cout << ans[a[i]] << ' ';
        cout << '\n';
    }
	return 0;
}