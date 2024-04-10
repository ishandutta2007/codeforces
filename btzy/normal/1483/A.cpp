#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for (int ct=0;ct!=tc;++ct){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(m, vector<int>());
        vector<int> choices(m,0);
        vector<int> counts(n,0);
        for (int i=0;i<m;++i){
            int ti;
            cin>>ti;
            for (int j=0;j<ti;++j){
                int x;
                cin>>x;
                --x;
                v[i].push_back(x);
            }
            choices[i]=v[i][0];
            counts[choices[i]]++;
        }
        int badindex=-1;
        int mval=(m+1)/2;
        for(int i=0;i<n;++i){
            if(counts[i]>mval){
                badindex=i;
                break;
            }
        }
        if (badindex!=-1){
            int giveaway=counts[badindex]-mval;
            for(int i=0;i<m&&giveaway>0;++i){
                if (choices[i]==badindex&&v[i].size()>1){
                    choices[i]=v[i][1];
                    --giveaway;
                }
            }
            if (giveaway>0){
                cout<<"NO\n";
                continue;
            }
        }
        cout<<"YES\n";
        for (int i=0;i<m;++i){
            if(i>0)cout<<' ';
            cout<<(choices[i]+1);
        }
        cout<<'\n';
    }
}