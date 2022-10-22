#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int neighb_max[550000];
vector<int> edge[550000];
int n, m, a, b, t;
vector<P> blogs;
int main(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &t);
        blogs.push_back(P(t, i));
    }

    sort(blogs.begin(), blogs.end());
    vector<int> ans;
    for(auto p:blogs){
        Int t = p.first;
        Int blog = p.second;
        if(neighb_max[blog]+1 != t){
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(blog);
        for(auto neighb: edge[blog]){
            if(neighb_max[neighb] == t-1){
                neighb_max[neighb] = t;
            }
        }
    }
    for(auto blog:ans)printf("%d ", blog);cout << endl;
    
    return 0;
}