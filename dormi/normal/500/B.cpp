#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=301;
int arr[MAXN];
char can[MAXN][MAXN];
pii dsu[MAXN];
vector<int> stff[MAXN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dsu[i]={i,1};
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>can[i][j];
            if(can[i][j]=='1'){
                uni(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        stff[find(i)].push_back(i);
    }
    for(int i=0;i<n;i++){
        if(find(i)==i) {
            sort(stff[i].begin(), stff[i].end());
            vector<int> te;
            for (int x:stff[i]) {
                te.push_back(arr[x]);
            }
            sort(te.begin(), te.end());
            for (int j = 0; j < sz(stff[i]); j++) {
                arr[stff[i][j]] = te[j];
            }
        }
    }
    for(int i=0;i<n;i++)printf("%d ", arr[i]);
    return 0;
}