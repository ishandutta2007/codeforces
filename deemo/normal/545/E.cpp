#include<iostream>
#include<vector>
#include<set>
#include<utility>

using namespace std;

struct Edge{
    int to , w , lab;
};

struct Thing{
    int first , forth , third;
    long long second;
};

long long n , m , ans , g;
const int max_n = 4 * 1e5;
vector<int> edges;
vector<Edge>	  vec[max_n];
long long save[max_n];
int dis[max_n];
int p[max_n];
int s[max_n];
bool mark[max_n];
set<Thing>  st;

bool operator <(Thing a , Thing b){
    if (a.second < b.second)    return  true;
    if (a.second == b.second && a.third < b.third)  return  true;
    if (a.second == b.second && a.third == b.third && a.first < b.first)    return	true;
    return  false;
}

void input(){
    cin >> n >> m;
    int a , b , c;
    Edge temp;
    for (int i = 0 ; i < m ; i++){
	 cin >> a >> b >> c;
	 a--;	  b--;

	 temp.to = b;
	 temp.w = c;
	 temp.lab = i + 1;
	 vec[a].push_back(temp);
	 temp.to = a;
	 vec[b].push_back(temp);
	 s[i + 1] = c;
    }
    cin >> g;
    g--;
}

void update(int v){
    int a , b , c , d;
    Thing temp;
    for (int i = 0 ; i < vec[v].size() ; i++){
	 a = v;  b = vec[v][i].to;  c = vec[v][i].w;	d = vec[v][i].lab;
	 temp.first = b;	temp.second = save[b];  temp.third = dis[b];    temp.forth = p[b];
	 if (mark[b] == 1)	continue;
	 if (save[b] == -1 || ((long long)(save[v] + c) < save[b] || ((long long)(save[v] + c) == save[b] && s[p[b]] > c))){
	     if (save[v] != -1)  st.erase(temp);
	     save[b] = (long long)(save[v] + c);
	     dis[b] = c;
	     p[b] = d;
	     temp.second = save[b];
	     temp.third = c;
	     temp.forth = d;
	     st.insert(temp);
	 }
    }  
}

void init(int v){
    for (int i = 0 ; i < n ; i++){
	 save[i] = -1;
	 dis[i] = -1;
	 p[i] = -1;
    }
    save[v] = 0;
    mark[v] = 1;
    update(v);
}

int find_min(){
    Thing temp;
    temp = *st.begin();
    st.erase(temp);
    ans += temp.third;
    mark[temp.first] = 1;
    edges.push_back(temp.forth);
    return  temp.first;
}

void dijk(int v){
    init(v);
    int mini;    

    for (int i = 1 ; i < n ; i++){
	 mini = find_min();
	 update(mini);
    }
}

int main(){
    input();
    dijk(g);
    cout << ans << endl;
    for (int i = 0 ; i < n - 1 ; i++){
	 if (i == n - 2) cout << edges[i] << endl;
	 else	  cout << edges[i] << " ";
    }
    return 0;
}