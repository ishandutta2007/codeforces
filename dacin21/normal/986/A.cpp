#include <bits/stdc++.h>

#define int long long
#define f first
#define vc vector
#define s second

using namespace std;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL_RUN
    freopen("input.txt", "r", stdin);
    int ttt;
    cin >> ttt;
    while(ttt--){
    #endif // LOCAL_RUN
    int n, m;

    int inf=10e18;
    cin >> n >> m; int k, s;
    cin >> k >> s;
    vector <vector <int> > adi (n);
    vector <vector <int> > dist (n, vector <int> (k, inf));
    int wer;
    vector <vector <int> > start(k);
    for (int i=0; i<n; i++){
        cin >> wer;
        dist[i][wer-1]=0;
        start[wer-1].push_back(i);

    }
    int temp, tamp;
    for (int i=0; i<m; i++){
        cin >> temp >> tamp;
        temp--; tamp--;
        adi[temp].push_back(tamp);
        adi[tamp].push_back(temp);
    }
   // cout << "a" << endl;

    for (int i=0; i<k; i++){
        //cout <<"stst" << endl;
        queue <int> pq;
        for (int j=0; j<start[i].size(); j++){
            pq.push(start[i][j]);
        }
        while(!pq.empty()){
            auto node=pq.front();
            pq.pop();
            for (int j=0; j<adi[node].size(); j++){
                int next=adi[node][j];
                if (dist[next][i]==inf){
                    dist[next][i]=dist[node][i]+1;
                    pq.push(next);
                }
            }
        }

    }
    for (int i=0; i<n; i++){
        nth_element(dist[i].begin(), dist[i].begin()+s, dist[i].end());
        int sum=0;
        for (int j=0; j<s; j++){
            sum+=dist[i][j];
        }
        cout  << sum << " ";
    }
    cout << "\n";





    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
}