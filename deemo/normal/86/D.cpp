/*
    I found myself in Wonderland
    Get back on my feet again..
*/

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

#define Query pair<pair<int , int> , int>
#define left first.first
#define right first.second

const int max_n = 2e5 + 20;
const int SQRT = 320;
const int MAX = 1e6 + 100;

bool help(Query a , Query b){
    if (a.left / SQRT < b.left / SQRT)  return  true;
    if (a.left / SQRT > b.left / SQRT)  return  false;
    return  a.right < b.right; 
}

int n , q;
ll sum;
Query query[max_n];
int vec[max_n];
ll ans[max_n];
int cnt[MAX];

void add(int x){
    sum -= ll(cnt[x]) * cnt[x] * x;
    cnt[x]++;
    sum += ll(cnt[x]) * cnt[x] * x;
}

void erase(int x){
    sum -= ll(cnt[x]) * cnt[x] * x;
    cnt[x]--;
    sum += ll(cnt[x]) * cnt[x] * x;
}

int main(){
    scanf("%d%d" , &n , &q);
    for (int i = 0 ; i < n ; i++)	 
	 scanf("%d" , &vec[i]);
    
    for (int i = 0 ; i < q ; i++){
	 int l , r;  scanf("%d%d" , &l , &r);    l--;
	 query[i] = {{l , r} , i};
    }   
    sort(query , query + q , help);

    int l = 0 , r = 0;
    for (int i = 0 ; i < q ; i++){
	 int ql = query[i].left, qr = query[i].right;
	 while (r < qr)  add(vec[r]), r++;
	 while (r > qr)  r--, erase(vec[r]);
	 while (l > ql)  l--, add(vec[l]);
	 while (l < ql)  erase(vec[l]), l++;
	 ans[query[i].second] = sum;
    }
    for (int i = 0 ; i < q ; i++)
	 printf("%I64d\n" , ans[i]);//cout << ans[i] << "\n";
    return 0;
}