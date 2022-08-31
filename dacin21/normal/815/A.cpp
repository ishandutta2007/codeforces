#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif // LOCAL_RUN
    cin.tie(0); ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > b(n, vector<int>(m));
    for(auto &e:b){
        for(auto &f:e){
            cin >> f;
        }
    }
    vector<int> x(n);
    vector<int> y(m);
    if(n<m){
        int a = *min_element(b[0].begin(), b[0].end());
        for(int i=0;i<m;++i){
            y[i] = b[0][i]-a;
        }
        for(int i=0;i<n;++i){
            x[i] = b[i][0] - y[0];
        }
    } else {
        int a = (*min_element(b.begin(), b.end()))[0];
        for(int i=0;i<n;++i){
            x[i] = b[i][0]-a;
        }
        for(int i=0;i<m;++i){
            y[i] = b[0][i] - x[0];
        }
    }
    bool f = false;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(b[i][j]!=x[i]+y[j]) f=true;
        }
    }
    if(f){
        cout << "-1";
        return 0;
    }
    int k = accumulate(x.begin(), x.end(), 0) + accumulate(y.begin(), y.end(), 0);
    cout << k << "\n";
    for(int i=0;i<n;++i){
        while(x[i]--){
            cout << "row " << 1+i << "\n";
        }
    }
    for(int i=0;i<m;++i){
        while(y[i]--){
            cout << "col " << 1+i << "\n";
        }
    }
    cout << flush;
    return 0;
}