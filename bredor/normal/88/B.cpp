//  228


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define yess "yes"
#define yesc "YES"
#define nos "no"
#define noc "NO"

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

#define M 100005
const int INF = 1000005;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first>b.first;
    return a.second > b.second;
}


void solve()
{
    int n, m, x;cin>>n>>m>>x;
    vector<vector<char>> v(n, vector<char>(m));
    vector<int> arr(26, 0);
    vector<pair<int, int>> shift;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            cin>>v[i][j];
            if(v[i][j] == 'S') { shift.push_back(make_pair(i, j));  continue;}
            arr[v[i][j] - 'a'] = 1;
        }

//    sort(all(shift), comp);

    map<char, int> mmap;

    for(auto e:shift){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int horz= abs(i-e.first) ;
                int vert= abs(j-e.second) ;
                if(horz*horz + vert*vert <= x*x && v[i][j]!='S')  mmap[v[i][j]] = 1 ;
            }
        }
    }



    int ans=0, k;cin>>k;
    for(int i=0; i<k; i++){
        char c;cin>>c;
        if(arr[tolower(c) - 'a'] == 0) {cout<<-1; return ;}
        if(isupper(c)){
            if(shift.size() == 0){
                cout<<-1;return;
            }
            if(!(mmap[tolower(c)]))ans++;
        }

    }
    cout<<ans;

}











int main()
{
    ios::sync_with_stdio(0);cin.tie(NULL);

    int t = 1;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

//     cin >> t;
    while(t--)
    {

        solve();

    }

    return 0;
}