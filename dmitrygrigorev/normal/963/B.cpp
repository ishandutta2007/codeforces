#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n==1){
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0; i < n; i++){
        int x;
        cin >> x;
        if (x!=0){
            data[i].push_back(x-1);
            data[x-1].push_back(i);
        }
    }
    vector<int> start, bck;
    vector<int> f, dlt(n);
    fill(dlt.begin(), dlt.end(), 0);
    for (int i=0; i < n; i++) f.push_back(data[i].size());
    queue<int> q;
    for (int i=0; i < n; i++) if (f[i] == 1) q.push(i);
    int ctr = 0;
    while (ctr < n-2){
        int el = q.front();
        q.pop();
        if (dlt[el] % 2 == 0){
            bck.push_back(el);
            for (int i=0; i < data[el].size(); i++){
                int to = data[el][i];
                dlt[to]++;
                f[to]--;
                if (f[to] == 1) q.push(to);
            }
        }
        else{
            start.push_back(el);
            for (int i=0; i < data[el].size(); i++){
                int to = data[el][i];
                f[to]--;
                if (f[to] == 1) q.push(to);
            }
        }
        ctr++;
    }
    int A = q.front();
    q.pop();
    int B = q.front();
    q.pop();
    if (dlt[A] % 2 == dlt[B] % 2){
        cout << "NO" << endl;
        return 0;
    }
    if (dlt[A] % 2) swap(A, B);
    bck.push_back(A);
    start.push_back(B);
    cout << "YES" << endl;
    for (int i=0; i < start.size(); i++) cout << start[i] + 1 << endl;
    reverse(bck.begin(), bck.end());
    for (int i=0; i < bck.size(); i++) cout << bck[i] + 1 << endl;
}