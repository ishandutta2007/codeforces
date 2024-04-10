#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<lli> gems[3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int r,g,b;
        cin>>r>>g>>b;
        lli a;
        for(int i=0;i<3;i++)gems[i].clear();
        for(int i=0;i<r;i++){
            cin>>a;
            gems[0].push_back(a);
        }
        for(int i=0;i<g;i++){
            cin>>a;
            gems[1].push_back(a);
        }
        for(int i=0;i<b;i++){
            cin>>a;
            gems[2].push_back(a);
        }
        for(int i=0;i<3;i++)sort(gems[i].begin(),gems[i].end());
        lli ans=LLONG_MAX;
        for(int i=0;i<3;i++){
            for(lli x:gems[i]){
                vector<lli> oth[2];
                int cnt=0;
                for(int j=0;j<3;j++){
                    if(j!=i){
                        int pos=lower_bound(gems[j].begin(),gems[j].end(),x)-gems[j].begin();
                        if(pos<sz(gems[j]))oth[cnt].push_back(gems[j][pos]);
                        pos--;
                        if(pos>=0)oth[cnt].push_back(gems[j][pos]);
                        cnt++;
                    }
                }
                for(int n=0;n<sz(oth[0]);n++){
                    for(int m=0;m<sz(oth[1]);m++){
                        ans=min(ans,(x-oth[0][n])*(x-oth[0][n])+(x-oth[1][m])*(x-oth[1][m])+(oth[0][n]-oth[1][m])*(oth[0][n]-oth[1][m]));
                    }
                }
            }
        }
        printf("%lli\n",ans);
    }
    return 0;
}