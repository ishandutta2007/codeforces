#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr;
        int in;
        for(int i=1;i<=n;i++){
            cin>>in;
            arr.push_back(in);
        }
        vector<int> pos;
        for(int i=1;i<=m;i++){
            cin>>in;
            pos.push_back(in);
        }
        sort(pos.begin(),pos.end());
        int l=0,r=0;
        for(int x:pos){
            if(x==r+1){
                r=x;
            }
            else{
                sort(arr.begin()+l,arr.begin()+r+1);
                l=x-1;
                r=x;
            }
        }
        sort(arr.begin()+l,arr.begin()+r+1);
        if(is_sorted(arr.begin(),arr.end()))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}