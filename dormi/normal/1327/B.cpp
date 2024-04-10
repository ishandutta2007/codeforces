#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<int> king;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        king.clear();
        for(int i=1;i<=n;i++)king.insert(i);
        int a,b;
        vector<int> bad;
        for (int i = 1; i <= n; i++) {
            cin>>a;
            bool work=false;
            while(a--){
                cin>>b;
                if(king.count(b)&&!work){
                    king.erase(b);
                    work=true;
                }
            }
            if(!work){
                bad.push_back(i);
            }
        }
        if(sz(bad)){
            printf("IMPROVE\n%d %d\n",*bad.begin(),*king.begin());
        }
        else printf("OPTIMAL\n");
    }
    return 0;
}