#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
vector<int> primes;
vector<pii> matrix[MAXN];
int dist[MAXN];
int ans=INT_MAX;
void test(int loc){
    for(int x:primes)dist[x]=INT_MAX;
    queue<pii> bfs;
    dist[loc]=0;
    bfs.push({loc,-1});
    while(sz(bfs)){
        auto cur=bfs.front();
        bfs.pop();
        for(auto x:matrix[cur.first]){
            if(dist[x.first]>dist[cur.first]+1){
                dist[x.first]=dist[cur.first]+1;
                bfs.push(x);
            }
            else if(x.second!=cur.second)ans=min(ans,dist[cur.first]+dist[x.first]+1);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    int sqr=1e3;
    for(int i=0;i<n;i++){
        cin>>a;
        vector<int> div;
        for(int j=2;j*j<=a;j++){
            int am=0;
            while(a%j==0){
                am++;
                a/=j;
            }
            if(am%2)div.push_back(j);
        }
        if(a>1){
            if(sz(div)==2){
                if(div[1]!=a)swap(div[0],div[1]);
                div.pop_back();
            }
            else div.push_back(a);
        }
        if(sz(div)==2){
            primes.push_back(div[0]);
            primes.push_back(div[1]);
            matrix[div[0]].push_back({div[1],i});
            matrix[div[1]].push_back({div[0],i});
        }
        else if(sz(div)==1){
            primes.push_back(div[0]);
            primes.push_back(1);
            matrix[div[0]].push_back({1,i});
            matrix[1].push_back({div[0],i});
        }
        else{
            printf("1\n");
            return 0;
        }
    }
    sort(primes.begin(),primes.end());
    primes.erase(unique(primes.begin(),primes.end()),primes.end());
    for(auto x:primes)dist[x]=INT_MAX;
    for(auto x:primes){
        if(x<=sqr){
            test(x);
        }
    }
    if(ans==INT_MAX)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}