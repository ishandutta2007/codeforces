#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> ii;

typedef pair<set<int>, int> si;

bool comp(si &a, si &b){
    return a.first.size() < b.first.size();
}

int a, cnta;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<si> v(n);
    int tot = 0;
    for (int i = 0; i <  n; ++i){
        int k;
        cin >> k;
        tot += k;
        v[i].second = i;
        for (int j = 0; j < k; ++j){
            int c;
            cin >> c;
            v[i].first.insert(c);
        }
    }
    a = tot/n;
    cnta = n-tot%n;
    sort(v.begin(), v.end(), comp);
    
    vector<si > gives, takes;
    vector<int> sh(n, a);
    for (int i = cnta; i < n; ++i){
        sh[v[i].second] = a+1;
    }
    int mvs = 0;
    set<int> still_take;
    for (int i = 0; i < n; ++i){
        if (v[i].first.size() < sh[v[i].second]){
            mvs += sh[v[i].second] - v[i].first.size();
            takes.push_back(v[i]);
            still_take.insert(takes.size()-1);
        }
        else if (v[i].first.size() > sh[v[i].second]){
            gives.push_back(v[i]);
        }
    }
    map<int, int> dic;
    
    cout << mvs << endl;
    for (si x : gives){
        int cnt = 0;
        for (auto v : x.first){
            
            if (x.first.size() - cnt == sh[x.second]) break;
            while (dic[v] < takes.size()){
                if (still_take.lower_bound(dic[v]) == still_take.end()) ++dic[v];
                else{
                    int tmp = *(still_take.lower_bound(dic[v]));
                    
                    dic[v] = tmp;
                    if (takes[dic[v]].first.count(v)) ++dic[v];
                    else break;
                }
            }
            if (dic[v] != takes.size()){
                ++cnt;
                cout << x.second+1 << " " << takes[dic[v]].second+1 << " " << v << "\n";
                takes[dic[v]].first.insert(v);
                if (takes[dic[v]].first.size() == sh[takes[dic[v]].second]){
                    still_take.erase(dic[v]);
                }
                dic[v]++;
            }
        }
    }
}