#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e4+1;
bool gone[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,t;
    cin>>n>>t;
    queue<int> q;
    q.push(1);
    gone[1]=true;
    int a;
    for(int i=1;i<n;i++){
        cin>>a;
        if(gone[i]){
            gone[i+a]=true;
        }
    }
    if(gone[t])printf("YES\n");
    else printf("NO\n");
    return 0;
}