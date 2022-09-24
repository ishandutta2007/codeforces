#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long int n,k; //  
vector<int> g[100000]; // 
bool used[100000];
vector <int> m;
vector<int> ans;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ans.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i < k; ++i)
        if (!used[m[i]])
            dfs (m[i]);
    //reverse (ans.begin(), ans.end());
}


vector<int> cl;
vector<int> p;
int cycle_st, cycle_end;

bool dfser (int v) {
    cl[v] = 1;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (cl[to] == 0)
        {
            p[to] = v;
            if (dfser(to))  return true;
        }
        else if (cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}


int main()
{
    
    cin >> n >> k;
    for(int i = 0 ; i< k; i++)
    {
        int p;
        cin >> p;
        m.push_back(p-1);
    }
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        for(int j = 0; j < t; j++)
        {
            int p;
            cin >> p;
            g[i].push_back(p-1);
        }
    }
    topological_sort();
    bool flag = 0;
    p.assign (n, -1);
    cl.assign (n, 0);
    cycle_st = -1;
    for(int i = 0; i < ans.size(); i++)
        if (dfser (ans[i]))
            break;
    
    if (cycle_st != -1)
        
        flag = 1;
    

    
  if(flag)
  {
      cout << -1;
      return 0;
  }
    //for(int i = 0; i < n; i++)
    //cout << g[i].size() << " ";
    cout << ans.size() << '\n' ;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i]+1 << " ";
    return 0;
}